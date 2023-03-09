#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
class subject;

class observer
{
public:
    virtual ~observer() {}
    virtual void update(subject* changed_sub) = 0;
protected:
    observer(){}
};

class subject {
public:
    virtual ~subject() {}
    virtual void attach(observer* o) { _observers.push_back(o); }
    virtual void detach(observer* o) { _observers.erase(find(_observers.begin(), _observers.end(), o)); }
    virtual void notify()
    {
        for (int i = 0; i < _observers.size(); ++i)
            _observers[i]->update(this);
    }

protected:
    subject() {}
    
private:
    vector<observer*> _observers;
};

class clock_time : public subject
{
public:
    clock_time() : _time("0:0:0") {}
    void tick() { _time = to_string(time(NULL)); notify(); }
    string get_time() { return _time; }
private:
    string _time;
};

class digital_clock : public observer
{
public:
    digital_clock(clock_time* s) { _subj = s; _subj->attach(this); }
    virtual ~digital_clock() { _subj->detach(this); }
    virtual void update(subject* s) { if(s == _subj) draw(); }
    virtual void draw() { cout << "digital draw -> " + _subj->get_time() << endl; }

private:
    clock_time* _subj;
};

class analog_clock : public observer
{
public:
    analog_clock(clock_time* s) { _subj = s; _subj->attach(this); }
    virtual ~analog_clock() { _subj->detach(this); }
    virtual void update(subject* s) { if(s == _subj) draw(); }
    virtual void draw() { cout << "analog draw -> " + _subj->get_time() << endl; }

private:
    clock_time* _subj;
};

int main()
{
    clock_time* timer = new clock_time;
    analog_clock* analogClock = new analog_clock(timer);
    digital_clock* digitalClock = new digital_clock(timer);
    analogClock->draw();
    digitalClock->draw();
    timer->tick();
    analogClock->draw();
    digitalClock->draw();
    return 0;
}