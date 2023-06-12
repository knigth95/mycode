#include <bits/stdc++.h>
using namespace std;
unsigned short func1(unsigned short si){
    return(si*256);
}
unsigned short func2(unsigned short si){
    return(si/256);
}
short func3(unsigned short si){
    short x=((short)si*256);
    return x/256;
}
short func4(unsigned short si){
    unsigned short x=(si*256);
    return (short)(x/256);
}
int main(){
    unsigned short si;
    cin>>si;
    cout<<func1(si)<<endl;
    cout<<func2(si)<<endl;
    cout<<func3(si)<<endl;
    cout<<func4(si)<<endl;
}