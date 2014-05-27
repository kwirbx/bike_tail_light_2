#include <Tween.h>
#include <iostream>

using namespace std;

Tween::Tween(int range[], int duration){
	std::cout << "made tween\n";

	// TODO - ensure values are valid
	_domain[0] = 0;
	_domain[1] = duration;

	// there has to be a better way to
	// assign one array to another :/
	_range[0] = range[0];
	_range[1] = range[1];

	// do we need to even store duration?
	_duration = duration;

	_currFrame = 0;

	_isDone = false;

	_scaleLinear(10);
}

void Tween::tick(){
	if(_isDone){
		return;
	} else {
		_currFrame++;
		if(_currFrame == _duration){
			_isDone = true;
		}
	}	
}

int Tween::getX(){
	return _scaleLinear(_currFrame);
}


int Tween::_scaleLinear(int x){
	float scaleFactor = float(x) / _domain[1];
	int result = scaleFactor * (_range[1] - _range[0]) + _range[0];
	return result;
}