#ifndef FSM_H
#define FSM_H
#include <vector>

namespace FSM
{
	class State;
	class Machine
	{
	protected: 
		int _currentState;
		std::vector<State*> _states;


	public:
		Machine() : _currentState(-1) { /*do nothing*/; }
		Machine(const std::vector<State*>& aSetOfStates) : _states(aSetOfStates), _currentState(0) { /*do nothing*/; }
		virtual ~Machine() { /*do nothing*/; }
		inline State* getCurrentState() { return _states[_currentState]; }

		void setState(const int aState);
	};

	class State
	{
	protected:
		int _id;

	public:
		State(const int anId) : _id(anId) { /*do nothing*/; }
		virtual ~State() {/*do nothing*/; }

		virtual void onEnter(Machine* aMachine)	{ /*do nothing*/; }
		virtual void onExit(Machine* aMachine)	{ /*do nothing*/; }
		virtual void update(Machine* aMachine)	{ /*do nothing*/; }

		int getId() const { return _id; }

	};

	void Machine::setState(const int aState)
	{
		if (_currentState < _states.size() && nullptr != _states[_currentState]) { _states[_currentState]->onExit(this); }
		_currentState = aState;
		if (_currentState < _states.size() && nullptr != _states[_currentState]) { _states[_currentState]->onEnter(this); }
	}
}
#endif // !FSM_H
