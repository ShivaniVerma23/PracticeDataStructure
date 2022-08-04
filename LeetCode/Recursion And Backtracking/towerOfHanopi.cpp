/*Tower of Hanoi is a mathematical puzzle where we have three pegs and n disks. The objective of the puzzle is to move the entire stack to another peg, obeying the following simple rules:

Only one disk can be moved at a time.
Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
No disk may be placed on top of a smaller disk.
Given n denoting the number of disks in the first peg, return all the steps required to move all disks from the first peg to the third peg in minimal number of steps.*/

#include <iostream>
#include <vector>

using namespace std;

void hanoi_steps(int n, int src, int dest, int aux, vector<vector<int>> &final)
{
    if (n == 0)
    {
        return;
    }
    hanoi_steps(n - 1, src, aux, dest, final);
    final.push_back({src, dest});
    hanoi_steps(n - 1, aux, dest, src, final);
 

    return;
}

vector<vector<int>> tower_of_hanoi(int n)
{
    // Write your code here.
    vector<vector<int>> final;
    int src{1};
    int dest{3};
    int aux{2};

    hanoi_steps(n, src, dest, aux, final);
    return final;
}

int main()
{
    int num{4};

    vector<vector<int>> result;

    result = tower_of_hanoi(num);

    for (auto it = result.begin(); it != result.end(); it++)
    {
        cout << "[";
        for (auto itr = it->begin(); itr != it->end(); itr++)
        {
            cout << *itr << " ";
        }
        cout << "]" << endl;
    }
}
