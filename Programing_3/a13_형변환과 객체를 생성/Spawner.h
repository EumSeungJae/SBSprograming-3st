#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory> // 스마트 포인터, 포인터를 객체화한 클래스

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;

// 1. Factory클래스 ( 열거형을 읽어서 자신의 타입에 맞는 클래스를 생성해주는 클래스)
// 2. Spawner클래스는 Factory클래스를 사용해서 클래스를 생성한다.
// 특정 클래스를 사용하는 클래스를 만들어라
// 포인터를 사용하는 클래스. 스마트 포인터
// gmaeObject 

enum class MoveType : int
{
    Normal = 0,
    Jump = 1,
    Dash = 2
};


class Run
{
public:
    int x;
    int y;
    std::string shape;
    int speed;
    MoveType moveType;

    Run(int _x, int _y, const std::string& _shape, int _speed)
        : x(_x), y(_y), shape(_shape), speed(_speed), moveType(MoveType::Normal)
    {
    }

    virtual ~Run() {}

    // ===== 추가된 함수 =====
    virtual void move()
    {
        std::cout << "Run합니다." << std::endl;
    }
};

class Dash : public Run
{
public:
    int dashPower;

    Dash(int _x, int _y, const std::string& _shape, int _speed, int _dashPower)
        : Run(_x, _y, _shape, _speed), dashPower(_dashPower)
    {
        moveType = MoveType::Dash;
    }

    void move() override
    {
        std::cout << "Dash합니다. 대시력: " << dashPower << std::endl;
    }
};


class Jump : public Run
{
public:
    int jumpPower;

    Jump(int _x, int _y, const std::string& _shape, int _speed, int _jumpPower)
        : Run(_x, _y, _shape, _speed), jumpPower(_jumpPower)
    {
        moveType = MoveType::Jump;
    }

    void move() override
    {
        std::cout << "Jump합니다. 점프력: " << jumpPower << std::endl;
    }
};


#include "rapidjson/document.h"

class RunFactory
{
public:
    static Run* CreateFromJson(const rapidjson::Value& value)
    {
        // ===== 공통 데이터 =====
        int x = value["x"].GetInt();
        int y = value["y"].GetInt();
        std::string shape = value["shape"].GetString();
        int speed = value["speed"].GetInt();

        // int → enum 형변환
        MoveType type =
            static_cast<MoveType>(value["moveType"].GetInt());

        // ===== 타입별 생성 =====
        switch (type)
        {
        case MoveType::Normal:
            return new Run(x, y, shape, speed);

        case MoveType::Jump:
        {
            int jumpPower = value["jumpPower"].GetInt();
            return new Jump(x, y, shape, speed, jumpPower);
        }

        case MoveType::Dash:
        {
            int dashPower = value["dashPower"].GetInt();
            return new Dash(x, y, shape, speed, dashPower);
        }

        default:
            return nullptr;
        }
    }
};

// RunFactory클래스를 이용해서 run객체를 vector에 저장해서 사용하는 Spawn클래스를 만들어라

class Spawner
{
private:
    std::vector<Run*> runs;

public:
    ~Spawner()
    {
        Clear();
    }

    // ===== JSON 로드 =====
    void Load()
    {
        const std::string filename = "run_Object.json";

        std::ifstream ifs(filename);
        if (!ifs.is_open())
        {
            std::cout << "파일 열기 실패: " << filename << std::endl;
            return;
        }

        // sstream 없이 전체 읽기
        std::string json(
            (std::istreambuf_iterator<char>(ifs)),
            std::istreambuf_iterator<char>()
        );
        ifs.close();

        rapidjson::Document doc;
        doc.Parse(json.c_str());

        if (doc.HasParseError())
        {
            std::cout << "JSON 파싱 오류" << std::endl;
            return;
        }

        Clear();

        if (doc.IsArray())
        {
            for (auto& value : doc.GetArray())
            {
                Run* run = RunFactory::CreateFromJson(value);
                if (run)
                    runs.push_back(run);
            }
        }
        else if (doc.IsObject())
        {
            Run* run = RunFactory::CreateFromJson(doc);
            if (run)
                runs.push_back(run);
        }
    }

    // ===== 실행 / 출력 =====
    void Display() const
    {
        std::cout << "=== Spawned Objects ===" << std::endl;

        for ( Run* run : runs)
        {
            run->move();   // 다형성
        }
    }

    void Clear()
    {
        for (Run* run : runs)
            delete run;

        runs.clear();
    }
};
