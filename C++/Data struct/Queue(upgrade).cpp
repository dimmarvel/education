#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
enum state_queue
{
    WORRY = -1,
    CHILL = 2
};

void come(vector<state_queue>& queue, int operation)
{
    if (operation > 0)
    {
        for (int i = 0; i < operation; i++)
        {
            queue.push_back(CHILL);
        }
    }
    else
    {
        for (int i = 0; i > operation; i--)
        {
            queue.pop_back();
        }
    }
}

void worry(vector<state_queue>& queue, int operation) { queue[operation] = WORRY; }

void quite(vector<state_queue>& queue, int operation) { queue[operation] = CHILL; }

void worry_count(const vector<state_queue>& queue)
{
    int counter = 0;
    for (auto it : queue)
    {
        if (it == WORRY)
            counter++;
    }
    cout << counter << endl;
}

int main()
{

    vector<state_queue> queue;
    vector<pair<string, int>> stack;

    int N;
    string state;
    int operation;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> state;
        if (state != "WORRY_COUNT")
        {
            cin >> operation;
        }
        else
        {
            operation = 0;
        }

        stack.push_back(make_pair(state, operation));
    }

    for (auto it : stack)
    {
        if (it.first == "WORRY")
        {
            worry(queue, it.second);
        }
        else if (it.first == "QUIET")
        {
            quite(queue, it.second);
        }
        else if (it.first == "COME")
        {
            come(queue, it.second);
        }
        else if (it.first == "WORRY_COUNT")
        {
            worry_count(queue);
        }
    }

    queue.clear();
    stack.clear();
    return 0;
}
