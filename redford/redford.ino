#include <Arduboy.h>


Arduboy arduboy;

byte x;
byte y;


void setup() {

  arduboy.begin();
  arduboy.setFrameRate(30);

  x = (WIDTH / 2);
  y = (HEIGHT / 2);
}

void loop() {

	if(!arduboy.nextFrame()){
		return;
	}

	arduboy.clear();

	update();

	arduboy.display();

}

class Object;

class Component{
	private:
		Object* gameObject;
	public:
		void getGameObject(){return gameObject;}
};

class Behaviour : public Component{
	private:
		bool hasStarted;
	public:
		virtual void awake();
		virtual void start();
		virtual void update();
		virtual void onDestroy();
};

class Renderer{
	public:
		virtual void render();
};

struct V2{
	public:
	float x;
	float y;
};

class Transform{
	public:
	V2 position;
	float rotation;
};


class Object{
	private:
		Transform* transform;
		Behaviour* behaviour;
		Renderer* renderer;
	public:
		void update(){
			behaviour->update();
			renderer->render();
		}
};

void update(){
	arduboy.setCursor(4, 9);

	auto func = [] () { arduboy.print(F("Hello redford")); };
	func(); // now call the function

}
