#include <iostream>
#include <Tween.h>

using namespace std;

main(){

	// range[0] is starting value
	// range[1] is ending value
	int range [2] = {0, 255};
	// duration in frames
	int duration = 10;

	// create a tween for each subpixel
	// (red, green, blue) and use the same
	// duration. realistically the range would
	// differ from subpixel to subpixel
	Tween r(range, duration);
	Tween g(range, duration);
	Tween b(range, duration);

	// "play" each tween a frame at a time
	// and output the value
	while(!r.isDone()){
		r.tick();
		g.tick();
		b.tick();
		cout << "r: " << r.getX();
		cout << " g: " << g.getX();
		cout << " b: " << b.getX();
		cout << "\n";
	}
}

