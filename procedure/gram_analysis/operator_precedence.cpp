#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
char table[128][128];
string VT="+-*/^()i#";
string Input_S,s;//输入串,字符栈
int stp,k;//stp为输入串的读入索引
int static cont=0;
char a;//当前读入字符
int Len;//len为输入字符串长度
void grammer_display()
{
    cout<<setw(50)<<"grammer"<<endl;
    cout.fill(1);
    cout<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<endl;
    cout<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<endl;
    cout.fill(' ');
    cout<<setw(10)<<VT[0]<<setw(10)<<VT[1]<<setw(10)<<VT[2]<<setw(10)<<VT[3]<<setw(10)<<VT[4]<<setw(10)<<VT[5]<<setw(10)<<VT[6]<<setw(10)<<VT[7]<<setw(10)<<VT[8]<<endl;
    cout<<VT[0]<<setw(9)<<table[VT[0]][VT[0]]<<setw(10)<<table[VT[0]][VT[1]]<<setw(10)<<table[VT[0]][VT[2]]<<setw(10)<<table[VT[0]][VT[3]]<<setw(10)<<table[VT[0]][VT[4]]<<setw(10)<<table[VT[0]][VT[5]]<<setw(10)<<table[VT[0]][VT[6]]<<setw(10)<<table[VT[0]][VT[7]]<<setw(10)<<table[VT[0]][VT[8]]<<endl;
    cout<<VT[1]<<setw(9)<<table[VT[1]][VT[0]]<<setw(10)<<table[VT[1]][VT[1]]<<setw(10)<<table[VT[1]][VT[2]]<<setw(10)<<table[VT[1]][VT[3]]<<setw(10)<<table[VT[1]][VT[4]]<<setw(10)<<table[VT[1]][VT[5]]<<setw(10)<<table[VT[1]][VT[6]]<<setw(10)<<table[VT[1]][VT[7]]<<setw(10)<<table[VT[1]][VT[8]]<<endl;
    cout<<VT[2]<<setw(9)<<table[VT[2]][VT[0]]<<setw(10)<<table[VT[2]][VT[1]]<<setw(10)<<table[VT[2]][VT[2]]<<setw(10)<<table[VT[2]][VT[3]]<<setw(10)<<table[VT[2]][VT[4]]<<setw(10)<<table[VT[2]][VT[5]]<<setw(10)<<table[VT[2]][VT[6]]<<setw(10)<<table[VT[2]][VT[7]]<<setw(10)<<table[VT[2]][VT[8]]<<endl;
    cout<<VT[3]<<setw(9)<<table[VT[3]][VT[0]]<<setw(10)<<table[VT[3]][VT[1]]<<setw(10)<<table[VT[3]][VT[2]]<<setw(10)<<table[VT[3]][VT[3]]<<setw(10)<<table[VT[3]][VT[4]]<<setw(10)<<table[VT[3]][VT[5]]<<setw(10)<<table[VT[3]][VT[6]]<<setw(10)<<table[VT[3]][VT[7]]<<setw(10)<<table[VT[3]][VT[8]]<<endl;
    cout<<VT[4]<<setw(9)<<table[VT[4]][VT[0]]<<setw(10)<<table[VT[4]][VT[1]]<<setw(10)<<table[VT[4]][VT[2]]<<setw(10)<<table[VT[4]][VT[3]]<<setw(10)<<table[VT[4]][VT[4]]<<setw(10)<<table[VT[4]][VT[5]]<<setw(10)<<table[VT[4]][VT[6]]<<setw(10)<<table[VT[4]][VT[7]]<<setw(10)<<table[VT[4]][VT[8]]<<endl;
    cout<<VT[5]<<setw(9)<<table[VT[5]][VT[0]]<<setw(10)<<table[VT[5]][VT[1]]<<setw(10)<<table[VT[5]][VT[2]]<<setw(10)<<table[VT[5]][VT[3]]<<setw(10)<<table[VT[5]][VT[4]]<<setw(10)<<table[VT[5]][VT[5]]<<setw(10)<<table[VT[5]][VT[6]]<<setw(10)<<table[VT[5]][VT[7]]<<setw(10)<<table[VT[5]][VT[8]]<<endl;
    cout<<VT[6]<<setw(9)<<table[VT[6]][VT[0]]<<setw(10)<<table[VT[6]][VT[1]]<<setw(10)<<table[VT[6]][VT[2]]<<setw(10)<<table[VT[6]][VT[3]]<<setw(10)<<table[VT[6]][VT[4]]<<setw(10)<<table[VT[6]][VT[5]]<<setw(10)<<table[VT[6]][VT[6]]<<setw(10)<<table[VT[6]][VT[7]]<<setw(10)<<table[VT[6]][VT[8]]<<endl;
    cout<<VT[7]<<setw(9)<<table[VT[7]][VT[0]]<<setw(10)<<table[VT[7]][VT[1]]<<setw(10)<<table[VT[7]][VT[2]]<<setw(10)<<table[VT[7]][VT[3]]<<setw(10)<<table[VT[7]][VT[4]]<<setw(10)<<table[VT[7]][VT[5]]<<setw(10)<<table[VT[7]][VT[6]]<<setw(10)<<table[VT[7]][VT[7]]<<setw(10)<<table[VT[7]][VT[8]]<<endl;
    cout<<VT[8]<<setw(9)<<table[VT[8]][VT[0]]<<setw(10)<<table[VT[8]][VT[1]]<<setw(10)<<table[VT[8]][VT[2]]<<setw(10)<<table[VT[8]][VT[3]]<<setw(10)<<table[VT[8]][VT[4]]<<setw(10)<<table[VT[8]][VT[5]]<<setw(10)<<table[VT[8]][VT[6]]<<setw(10)<<table[VT[8]][VT[7]]<<setw(10)<<table[VT[8]][VT[8]]<<endl;
    cout.fill(1);
    cout<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<endl;
    cout<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<endl;

}
void init()
{
    for(int i=0; i<128; i++)
        for(int j=0; j<128; j++)
            table[i][j]=' ';
    table['+']['+']='>';
    table['+']['-']='>';
    table['+']['*']='<';
    table['+']['/']='<';
    table['+']['^']='<';
    table['+']['(']='<';
    table['+'][')']='>';
    table['+']['i']='<';
    table['+']['#']='>';

    table['-']['+']='>';
    table['-']['-']='>';
    table['-']['*']='<';
    table['-']['/']='<';
    table['-']['^']='<';
    table['-']['(']='<';
    table['-'][')']='>';
    table['-']['i']='<';
    table['-']['#']='>';

    table['*']['+']='>';
    table['*']['-']='>';
    table['*']['*']='>';
    table['*']['/']='>';
    table['*']['^']='<';
    table['*']['(']='<';
    table['*'][')']='>';
    table['*']['i']='<';
    table['*']['#']='>';

    table['/']['+']='>';
    table['/']['-']='>';
    table['/']['*']='>';
    table['/']['/']='>';
    table['/']['^']='<';
    table['/']['(']='<';
    table['/'][')']='>';
    table['/']['i']='<';
    table['/']['#']='>';

    table['^']['+']='>';
    table['^']['-']='>';
    table['^']['*']='>';
    table['^']['/']='>';
    table['^']['^']='<';
    table['^']['(']='<';
    table['^'][')']='>';
    table['^']['i']='<';
    table['^']['#']='>';

    table['(']['+']='<';
    table['(']['-']='<';
    table['(']['*']='<';
    table['(']['/']='<';
    table['(']['^']='<';
    table['(']['(']='<';
    table['('][')']='=';
    table['(']['i']='<';
    table['(']['#']=' ';

    table[')']['+']='>';
    table[')']['-']='>';
    table[')']['*']='>';
    table[')']['/']='>';
    table[')']['^']='>';
    table[')']['(']=' ';
    table[')'][')']='>';
    table[')']['i']=' ';
    table[')']['#']='>';

    table['i']['+']='>';
    table['i']['-']='>';
    table['i']['*']='>';
    table['i']['/']='>';
    table['i']['^']='>';
    table['i']['(']=' ';
    table['i'][')']='>';
    table['i']['i']=' ';
    table['i']['#']='>';

    table['#']['+']='<';
    table['#']['-']='<';
    table['#']['*']='<';
    table['#']['/']='<';
    table['#']['^']='<';
    table['#']['(']='<';
    table['#'][')']=' ';
    table['#']['i']='<';
    table['#']['#']='=';
    stp=0;
    k=0;
    s[k]='#';
    a=Input_S[stp];
}
bool Is_VT(char xx)
{
    for(int i=0; i<9; i++)
        if(xx==VT[i])
            return true;
    return false;
}
void display()//输出表头
{
    cout<<"\t\t\t\t\t分析表\n\n\n";
    cout.fill(' ');
    //cout<<setw(20)<<"!"<<setw(20)<<"!"<<setw(20)<<"!"<<setw(20)<<"!\n";
    cout<<setw(20)<<"步骤"<<setw(20)<<"栈"<<setw(20)<<"优先关系"<<setw(20)<<"当前符号"<<setw(25)<<"剩余输入串"<<setw(20)<<"移近或归约\n";
    cout.fill(' ');
}
void Algorithm()
{
    //cout<<"######################"<<stp<<"############"<<endl;

    char Q;
    int i;
    bool GY=false;//标志归约还是移进
    string temp,temps;//临时归约串
    int j,t=0;
//    for(int i=stp+1;i<Input_S.length();i++)//剩余输入符号
//        temp[t++]=Input_S[i];
//    temp[t]='\0';
//    for(i=0;i<=k;i++)//栈
//            temps[i]=s[i];
//    temps[i]='\0';
//    cout<<temp<<endl;
//    cout<<temps<<endl;
    bool b=Is_VT(s[k]);//如果当前栈顶是终结符则j=k,否则j=k-1
    cont++;//步骤+1
    if(b)
        j=k;
    else
        j=k-1;
    if(cont!=1)
        a=Input_S[stp];//当前输入字符给a
    //cout<<"栈顶符号"<<s[j]<<"当前符号"<<a<<endl;
    cout<<setw(20)<<cont;
    if(cont<=9)
            cout<<setw(20);
        else
            cout<<setw(20);
    if(s[j]>a)//当前输入字符优先级较低，则可能需要归约
    {
        for(i=0;i<=k;i++)
        {
            temps[i]=s[i];
            cout<<temps[i];
        }
        temps[i]='\0';
        cout<<setw(20-i)<<table[s[j]][a];
        //cout<<temps<<endl;
        //cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
        Q=s[j];
        while(s[j]>=Q)//找到归约的字符串
        {
            Q=s[j];
            if(Is_VT(s[j-1]))
                j--;
            else
                j-=2;
        }
        GY=true;//找到了要归约的字符串
        cout<<setw(20)<<a<<setw(20);
        for(i=stp+1,t=0;i<Len;t++,i++)
        {
            temp[t]=Input_S[i];
             cout<<temp[t];
        }
        k=j+1;
        s[k]='N';
        s[k+1]='\0';
        if(stp+1>=Len)
            cout<<setw(40);
        else
            cout<<setw(21-t);
        cout<<"归约\n";
        Algorithm();
    }
    else//可能需要移近
    {
        //cout<<"********************************"<<a<<endl;

        for(i=0;i<=k;i++)
         {
             temps[i]=s[i];
             cout<<temps[i];
         }
         cout<<setw(20-i)<<table[s[j]][a]<<setw(20)<<a;
        cout<<setw(20);
        for(i=stp+1;i<Len;i++)
            cout<<Input_S[i];
        if(s[j]<a)//当前输入字符优先级低，移近
        {
            k++;
            s[k]=a;
            stp++;
        }else{
            if(s[j]==a){
                if(s[j]=='#'){
                    if(stp+1==Len){
                        cout<<setw(39)<<"接受\n\n\n\t\t\t恭喜女王大人，输入的表达式完全符合文法哦！继续努力哦！\n\n"<<endl;
                        return ;
                    }else{
                        cout<<"ERROR\n\n\t\t\t好忧桑~~~女王大人出错了"<<endl;
                        return ;
                    }
                }else{
                    k++;
                    s[k]=a;
                    stp++;
                }
            }else{
                cout<<"ERROR\n\n\t\t\t好忧桑~~~女王大人出错了"<<endl;
                return ;
                //cout<<"*************111"<<endl;
            }
        }
        cout<<setw(20-Len+stp+1)<<"移近\n";
        Algorithm();
    }

//    cout<<setw(20)<<temps<<setw(20)<<table[s[j]][a]<<setw(20)<<a<<setw(20)<<temp;//输出优先关系当前符号
//    if(GY)
//       cout<<setw(20)<<"归约"<<endl;
//    else
//        cout<<setw(20)<<"移近"<<endl;
    //Algorithm();
}
void function()
{

    cont=0;
    cout<<"女王大人请输入喜欢的表达式"<<endl;
    cin>>Input_S;
    init();
    grammer_display();
    Len=Input_S.length();
    display();
    Algorithm();
    function();
}
int main()
{
    cout<<"\t\t\t算符优先文法\n\n\n";
    function();
    return 0;
}
