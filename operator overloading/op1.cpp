#include <iostream>
#include <string.h>
using namespace std;
class YoutubeChannel
{
public:
    string name;
    int subscriberscount;
    YoutubeChannel(string name, int sub_count)
    {
        this->name = name;
        this->subscriberscount = sub_count;
    }
};
void operator<<(ostream &COUT, YoutubeChannel &ytchannel) // overloading insertion operator
{
    COUT << "Name: " << ytchannel.name << endl;
    COUT << "Subscribers count: " << ytchannel.subscriberscount << endl;
}
int main()
{
    YoutubeChannel yt1 = YoutubeChannel("Gaming", 25000);
    cout << yt1;
    // operator<<(cout, yt1);
}