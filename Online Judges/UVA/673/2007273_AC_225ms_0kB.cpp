#include<bits/stdc++.h>
using namespace std;

int main()
{
    string braket;
    int tst;
    cin>>tst;
    getchar();
    while(tst--)
    {
        stack<char>stak;
        getline(cin,braket);
        int len=braket.size();
        int flg=0;
        // cout<<braket<<endl;
        for(int i=0; i<len; i++)
        {
            if(braket[i]=='('||braket[i]=='[')  stak.push(braket[i]);
            // cout<<stak.top()<<endl;
            //else if()  stak.push(braket[i]);
            else if(braket[i]==')'&&!stak.empty()&&stak.top()=='(')
            {
                flg=0;
                 stak.pop();
            }
            else if(braket[i]==']'&&!stak.empty()&&stak.top()=='[') 
            {
				flg=0;
				stak.pop();
			}   
            else
            {
                flg=1;
                //cout<<flg<<endl;
                goto mk;
            }
        }

        mk:
        if(flg==0&&stak.empty()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
