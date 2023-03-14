#include <iostream>
using namespace std;


bool matchesAt(string T,int p,string W)
{
    for(int i=0; i<=W.length()-1; i++)
    {
        if(W[i]!=T[i+p])
        {
            return false;
        }
    }
    return true;
}


int Naive(string T,string W)
{
    int p=0;
    int Tsize = T.length();
    int Wsize = W.length();

    while(p <= Tsize - Wsize)
    {
        if(matchesAt(T,p,W)==true)
        {
            cout<<"index p = "<<p<<endl;
            p++;
        }
        else
        {
            p++;
        }
    }
    return p;
}

int lastp(int p,string T,string W)
{
    int index = -1;
    char z=T[p+W.length()];

    for(int i=0; i<W.length(); i++)
    {
        if(W[i]==z)
        {
            index = i;
        }

    }
    return index;
}


int sunday(string T, string W)
{
    int p=0;
    int Tsize = T.length();
    int Wsize = W.length();

    while(p < Tsize - Wsize)
    {
        if(matchesAt(T,p,W)==true)
        {

            cout<<"index p = "<<p<<endl;
            p=p+(Wsize-lastp(p,T,W));
        }
        else
        {
            p=p+(Wsize-lastp(p,T,W));
        }
    }

    return p;
}


int main()
{
    string Text = "MODXQRJATYDIMOFUGCLQURCLQECDRHVQSUWBVNTMRYKTDLWIXOQLDSWTMHMJXQEDMODXQQKPRNGPROXVFPEUAGBSXEXJEGPQBGIMODXQTOBXMNSHEQIPOIEFCGXLVUMODXYWUECXWMLPLLFRFYGCAAQYQFHQHMHMDIUJJIVMODXQNWVGFNSAQMFKJYMXIUQCAQLYUVVXMODXQYSJGJDYSNANCRDSXIHVKRNOJQKBAYTGXDYITJOCUKSSXMODXAISFVXGOXJHWWNRNEPHIQPNGLCJWFDVMLAI";
    string Pattern = "MODXQ";

    cout<<"Text:"<<Text<<endl;
    cout<<"wzor:"<<Pattern<<endl<<endl;

    cout<<"NAIVE:"<<endl<<endl;

    Naive(Text,Pattern);
    cout<<endl;

    cout<<"SUNDAY:"<<endl<<endl;

    sunday(Text,Pattern);
    cout<<endl;

    return 0;
}



