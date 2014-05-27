#ifndef TWEEN_H
#define TWEEN_H

// TODO - loop, reverse
// TODO - start, stop, pause, rewind
// TODO - start delay, end delay

class Tween {
public: 
	// range: int array with 2 values: the min
	// and max values that the scale should return
	// duration: duration of the tween in frames
	Tween(int range[], int duration);

	// advances the playhead by one frame (or if
	// tween is reversing, reverses the playhead
	// by one frame)
	void tick();

	// returns the current output value
	int getX();

	// returns if this tween has played to completion
	// or not
	bool isDone(){ return _isDone; };

private:
	// examines _domain and _range, and given x
	// returns the current output value
	int _scaleLinear(int x);

	// input domain
	int _domain [2];

	// output range
	int _range [2];

	// current frame / playhead position
	int _currFrame;

	// duration of this tween in frames
	int _duration;

	// if tween has reached the last frame
	// or not
	bool _isDone;
};

#endif