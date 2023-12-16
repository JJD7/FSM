#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

#include "FSM.h"

enum STATE_ID
{
    OFF, 
    ON
};

class OnState : public FSM::State
{
public:
    OnState() : FSM::State(STATE_ID::ON) { /*do nothing*/; }
    void update(FSM::Machine* aMachine) override
    {
        aMachine->setState(STATE_ID::OFF);
    }
};

class OffState : public FSM::State
{
public:
    OffState() : FSM::State(STATE_ID::OFF) { /*do nothing*/; }
    void update(FSM::Machine* aMachine) override
    {
        aMachine->setState(STATE_ID::ON);
    }
};

class SimpleFSM : public FSM::Machine
{
public:
    SimpleFSM(const std::vector<FSM::State*>& aSetOfStates) : FSM::Machine(aSetOfStates) { /*do nothing*/; }
    ~SimpleFSM() override { /*do nothing*/; }
    void update()
    {
        _states[_currentState]->update(this);
    }
};

int main(int argc, char* argv[])
{
    std::cout << "Test" << '\n';

    OnState on;
    OffState off;
    SimpleFSM machine( { &off, &on } );

    std::cout << "Initial state: " << machine.getCurrentState()->getId() << std::endl;

    machine.update();

    std::cout << "Final state: " << machine.getCurrentState()->getId() << std::endl;

    return 0;
}