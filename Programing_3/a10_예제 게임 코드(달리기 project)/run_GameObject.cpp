#include "run_GameObject.h"
#include <conio.h>
run_GameObject::run_GameObject(
	int x, int y, string shape, int speed, int movetick)
	: x(x), y(y), shape(shape), speed(speed), movetick(movetick)
{
}

run_GameObject::run_GameObject()
	: run_GameObject(5, 5, "This is example", 3) {
}

void run_GameObject::update()
{
	// 속도 변수(3), 속도를 체크하는 tick(0)
	movetick++;
	if (speed <= movetick) // 내가 움직이고 싶은 속도에 도달했을 때
	{
		// 움직여라 코드. (다형성을 가지게 만들어라)
		move();


		movetick = 0;
	}
}

void run_GameObject::draw(ConsoleRenderer& console)
{
	console.Print(x, y, shape);
}

void run_GameObject::move()
{
	x--;
	if (x <= 0) { x = 80; }
}

jump_gameObject::jump_gameObject(
	int x, int y, string shape, int speed,
	int jumpPower,
	int movetick)
	:
	run_GameObject(x, y, shape, speed, movetick),
	jumpPower(jumpPower)
{
	jumpTime = 15;
	jumptick = 0;
	isGround = true;
}

jump_gameObject::jump_gameObject() :run_GameObject(), jumpPower(2)
{
	jumpTime = 15;
	jumptick = 0;
	isGround = true;
}

void jump_gameObject::move()
{
	jumptick++;
	if (jumpTime <= jumptick) // 내가 움직이고 싶은 속도에 도달했을 때
	{
		if (isGround) {
			y -= jumpPower;

		}
		else {
			y += jumpPower;
		}
		isGround = !isGround;

		jumptick = 0;
	}
	run_GameObject::move();
}

//burrow_gameObject::burrow_gameObject(
//	int x, int y, string shape, int speed, int burrowDepth, int movetick) :
//	run_GameObject(x, y, shape, speed, movetick), burrowDepth(burrowDepth)
//{
//	burrowTime = 15;
//	burrowtick = 0;
//	isGround = true;
//
//
//}
//
//
//burrow_gameObject::burrow_gameObject() :run_GameObject(), burrowDepth(2)
//{
//	burrowTime = 15;
//	burrowtick = 0;
//	isGround = true;
//}
//
//void burrow_gameObject::move()
//{
//	burrowtick++;
//	if (burrowTime <= burrowtick) // 내가 움직이고 싶은 속도에 도달했을 때
//	{
//		if (isGround) {
//			y += burrowDepth;
//
//		}
//		else {
//			y -= burrowDepth;
//		}
//		x++;
//		isGround = !isGround;
//
//		burrowtick = 0;
//	}
//	run_GameObject::move();
//
//
//}

dash_gameObject::dash_gameObject(
	int x, int y, string shape, int speed, int dashpower, int movetick)
	: run_GameObject(x,y,shape,speed), dashpower(dashpower)
{
	dashtick = 0;
	dashTime = 3;
}

dash_gameObject::dash_gameObject() : dash_gameObject(80,5,"this is example",3,1)
{
}

void dash_gameObject::move()
{
	dashtick++;
	if (dashTime <= dashtick) // 내가 움직이고 싶은 속도에 도달했을 때
	{
		dash();

		// x -= dashpower;

		dashtick = 0;
	}
	run_GameObject::move();
}

void dash_gameObject::dash()
{
	x -= dashpower;
}
