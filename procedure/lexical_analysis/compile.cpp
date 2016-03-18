#include<cstring>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<sstream>
using namespace std;
//关键字
char* key[]= {"if","else","for","while","do","return","int","void","main","break","continue","cout","float"};
//标识符
struct name
{
    char ID[20];
} name[1000];
int namenum=0;//标识符个数
//运算符
char* operate[]= {"%","+","#","-","*","/",">","<","=","++","--",">=","<=","==","!=","&&","||"};
//分界符
char* border[]= {",",";","{","}","(",")","[","]"};
//常数
struct num
{
    int num1;
    float num2;
    bool x1;//true时num1有数
    bool x2;//true时num2有数
} num[1000];
int numbernum=0;//常数个数
char* f1name="f1.txt";//二元组表
char* f2name="f2.txt";//常数表
char* f3name="f3.txt";//标识符表
FILE* f1,*f2,*f3;//三张表
int x;//读取的字符的位置
int i,j,k,f=0,len;
char A[20];//用来暂时存放字符串
string getsym="";//开始时没有读程序，所以是空串
string Array[100000];
int length;//程序的长度
int Len=0;//Array数组的长度
struct Siyuan
{
    string op;
    string w1;
    string w2;
    string step;
}Si[1000];
struct Goal
{
    int step;
    string G1;
    string G2;
    string G3;
}Goal[1000];
int Begin=1,END=2000,start=1;
void Read_file(char* s,string &getsym)
{
    FILE *fp;
    if((fp=fopen(s,"r"))!=NULL)
    {
        while(!feof(fp))//读取程序到getsym中
        {
            getsym+=fgetc(fp);
        }
    }
    cout<<getsym<<endl;
    fclose(fp);
}
void openfile()
{
    f1=fopen(f1name,"a");
    if(!f1)
    {
        f1=fopen(f1name,"w");
    }
    char* sm="1.关键字2.标识符3.常数4.运算符5.界符";//二元组表头
    fputs(sm,f1);//存二元组表头
    f2=fopen(f2name,"a");
    if(!f2)
    {
        f2=fopen(f2name,"w");
    }
    f3=fopen(f3name,"a");
    if(!f3)
    {
        f3=fopen(f1name,"w");
    }
}
void closefile()
{
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
void delete_blank()//滤掉空格、换行、Tab
{
    //cout<<x<<length<<endl;
    while(x<length&&(getsym[x]==' '||getsym[x]==9||getsym[x]==10))
        x++;

}
void character()//如果当前是字母
{
    k=0;//表示单词串的长度
    f=0;
    do
    {
        if(k<10)
            A[k++]=getsym[x++];
    }
    while(x<length&&(getsym[x]>='a'&&getsym[x]<='z'||getsym[x]>='0'&&getsym[x]<='9'));
    //strcpy(id,A);

    for(j=0; j<13; j++)
    {
        //string str(key[j]);
        if(strcmp(A,key[j])==0)
        {
            f=1;//找到匹配的关键字
            break;
        }
    }
    //cout<<A<<endl;
    if(f)//A是关键字,写入二元组
    {
        fputs("\n",f1);
        fputs(A,f1);
        string a(A);
        len=a.size();
        int ll=15-len;
        for(int t=0; t<ll; t++)
            fputs(" ",f1);
        fputs("1",f1);
    }
    else//A是标识符
    {
        //***标识符写入二元组***************************
        fputs("\n",f1);
        fputs(A,f1);
        string a(A);
        len=a.size();
        int ll=15-len;
        for(int t=0; t<ll; t++)
            fputs(" ",f1);
        fputs("2",f1);

        //****首次出现的标识符写入标识符表********************
        int p=0;
        for(int e=0; e<namenum; e++) //查找标识符是否出现过
            if(strcmp(name[e].ID,A)==0)
            {
                p=1;
                break;
            }

        if(!p)
        {

            strcpy(name[namenum++].ID,A);
            fputs("\n",f2);
            fputs(A,f2);
        }
    }
}
void Number()//是数字
{

    int start=x,end;//记录单词串的开始和结尾
    float number=0,number1=0;//number1暂时计算小数部分
    do
    {
        number=10*number+getsym[x++]-'0';
    }
    while(x<length&&getsym[x]>='0'&&getsym[x]<='9');
    if(getsym[x]=='.')//此时为浮点数
    {
        x++;
        do
        {
            number1=number1/10+getsym[x++]-'0';
        }
        while(x<length&&getsym[x]>='0'&&getsym[x]<='9');
        number+=number1;
        num[numbernum].num2=number;
        num[numbernum++].x2=true;
        //cout<<number<<endl;
    }
    else//此时为整数
    {
        num[numbernum].num1=(int)number;
        num[numbernum++].x1=true;
        //cout<<number<<endl;
    }
    end=x;
    memset(A,'\0',20*sizeof(char));
    for(int y=start,k=0; y<end; y++,k++)
        A[k]=getsym[y];
    fputs("\n",f3);
    fputs(A,f3);//将数字写入常数表
    //***将数字写入二元组
    fputs("\n",f1);
    fputs(A,f1);
    string a(A);
    len=a.size();
    int ll=15-len;
    for(int t=0; t<ll; t++)
        fputs(" ",f1);
    fputs("3",f1);

}
void Border()
{
    //***将分界符写入二元组
    fputs("\n",f1);
    fputs(border[i],f1);
    //strcpy(id,border[i]);
    string a(border[i]);
    len=a.size();
    int ll=15-len;
    for(int t=0; t<ll; t++)
        fputs(" ",f1);
    fputs("5",f1);
    x++;
    //cout<<border[i]<<endl;
}
//*****************************************************************

void Operate()
{
    //***判断当前是不是两个符号的运算符
    //cout<<"**********************1\n";
    memset(A,'\0',20*sizeof(char));
    f=0;
    for(i=9; i<17; i++)
    {
        //char* h;
        A[0]=getsym[x];
        if(x+1<length)
            A[1]=getsym[x+1];
        //cout<<A<<endl;
        if(strcmp(A,operate[i])==0)
        {
            f=1;
            break;
        }
    }
    if(f)//***当前是一个符号的运算符
    {
        //***将一个符号的运算符写入二元组
        fputs("\n",f1);
        fputs(operate[i],f1);
        //strcpy(id,operate[i]);
        string a(operate[i]);
        len=a.size();
        int ll=15-len;
        for(int t=0; t<ll; t++)
            fputs(" ",f1);
        fputs("4",f1);
        x+=2;
        //cout<<operate[i]<<endl;
    }
    else//***当前是两个符号的运算符或者是其他的规定之外的符号
    {
        f=0;
        memset(A,'\0',20*sizeof(char));
        A[0]=getsym[x];
        for(i=0; i<9; i++)
        {
            if(strcmp(A,operate[i])==0)
            {
                f=1;
                break;
            }
        }
        //cout<<A<<endl;
        if(f)//***当前是两个符号的运算符
        {
            //***将两个符号的运算符写入二元组
            fputs("\n",f1);
            fputs(operate[i],f1);
            //strcpy(id,operate[i]);
            string a(operate[i]);
            len=a.size();
            int ll=15-len;
            for(int t=0; t<ll; t++)
                fputs(" ",f1);
            fputs("4",f1);
            x++;
            //cout<<operate[i]<<endl;
        }
    }
}
///***************************************************************

void getSym()
{

    openfile();//打开文件
    for(x=0; x<=length-1;)
    {
        //cout<<getsym[82]<<endl;
        f=0;//标志变量初始化
        memset(A,'\0',20*sizeof(char));
        delete_blank();
        //*************判断当前是不是字母
        if(x<length&&getsym[x]>='a'&&getsym[x]<='z')
            character();
        else//当前单词串不是字母开头或者x>=length
        {

            if(x>=length)
                break;
            else if(getsym[x]>='0'&&getsym[x]<='9')//检测是否以数字0，，9开头
                Number();
            else//当前字符不是关键字/标识符/常数
            {
                //***判断当前是不是分界符*********

                f=0;
                memset(A,'\0',20*sizeof(char));
                A[0]=getsym[x];
                for(i=0; i<8; i++)
                {
                    if(strcmp(A,border[i])==0)
                    {
                        f=1;
                        break;
                    }
                }
                if(f)//当前是分界符
                {
                    Border();
                    if(x==length-1)
                        break;
                }
                else//当前不是分界符，是运算符或者错误符号
                {
                    //cout<<"*********************1\n";
                    Operate();
                    //cout<<"*********************2\n";
                }

            }

        }
    }
    closefile();
}
void Read_filef1(char* s)
{
    FILE* fp;
    int f;
    char c;
    string Prog="";
    if((fp=fopen(s,"r"))!=NULL)
    {
        fseek(fp,38,0);//过滤开始的标志
        while(!feof(fp))//过滤空格回车并将每个单词放入数组
        {
            c=fgetc(fp);
            if(c!=' '&&c!='\n')
                Prog+=c;
            else
            {
                while(c==' '||c=='\n')
                    c=fgetc(fp);
                Prog+='\0';
                Array[Len++]=Prog;
                Prog="";
                Prog+=c;
            }
        }
        Array[Len++]=Prog;
    }
    fclose(fp);
    for(int j=0;j<Len;j++)
        cout<<Array[j]<<endl;
}
char procede(char theta1,char theta2)//比较字符的优先级
{
    int row,col;
    char ch[10]="%=+-*/()#";
    char R[9][10]={{">>>>>><>>"},{"</<<<<</>"},{"</>><<<>>"},{"</>><<<>>"},{">/>>>><>>"},{">/>>>><>>"},{"</<<<<<=/"},{">/>>>>/>>"},{"<<<<<<</="}};
    for(int i=0;i<9;i++)
        if(ch[i]==theta1)
        {
            row=i;
            break;
        }
    for(int i=0;i<9;i++)
        if(ch[i]==theta2)
        {
            col=i;
            break;
        }
    if(row<9&&col<9)
        return R[row][col];
    else
        return '/';
}
bool Is_ZM(char c)
{
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'))
        return true;
    return false;
}
void CLEAR(stack<char> sta)
{
    while(!sta.empty())
        sta.pop();
}
void Num_Str(int x,string& mm)
{
    int c=0;
    char* sss;
    while(1)
    {
       sss[c++]=(x%10)+'0';
       x=x/10;
       if(x==0)
            break;
    }
    c--;
    for(;c>=0;)
        mm+=sss[c--];
    //cout<<mm<<endl;
}
void Biaodashi(string infixexp)//完成表达式的四元式
{
    //infixexp=infixexp.substr(2);
    infixexp+='#';
    //cout<<infixexp<<endl;
    stack<char> s;
    stack<char> sp;
    CLEAR(s);
    CLEAR(sp);
    char w,topelement;
    int i=0,j=0,h=0;
    s.push('#');
    w=infixexp[i];
    while(!s.empty())
    {
        //string y,y1,y2;
        //cout<<"w = "<<w<<endl;
        if(Is_ZM(w))
        {
            //cout<<"sp.top()="<<w<<endl;
            sp.push(w);
            i=i+2;
            w=infixexp[i];
        }
        else
        {
            topelement=s.top();
            switch(procede(topelement,w))
            {
                case '>':
                    {
                         string y="",y1="",y2="";
                         char c,c1,c2;
                         c=s.top();
                         y+=c;
                         s.pop();
                         //cout<<"****************8\n";
                         c1=sp.top();
                         y1+=c1;
                         sp.pop();
                         //cout<<"****************9\n";
                         c2=sp.top();
                         y2+=c2;
                         sp.pop();
                         //cout<<" y1.length ="<<y1.length()<<endl;
                         //cout<<"y1="<<y1<<"  y2="<<y2<<endl;
                         Si[Begin].op=y;
                         Si[Begin].w1=y1;
                         if(c=='=')
                         {
                             Si[Begin].w2="-";
                             Si[Begin++].step=y2;
                         }
                         else
                         {
                             Si[Begin].w2=y2;
                             //Num_Str(Begin+1,u);
                             Si[Begin++].step='A'+h;
                             sp.push('A'+h);
                             h++;
                         }
                         break;
                    }
                case '=':{

                         s.pop();
                         if(w!='#')
                         {
                             i=i+2;
                             w=infixexp[i];
                         }

                         break;
                }
                case '<':{//cout<<"****************3\n";
                         s.push(w);
                         i=i+2;
                         w=infixexp[i];
                         break;
                }
                case '/':cout<<"************4\n";
                         break;
                default:cout<<"中缀表达式非法"<<endl;
            }

        }
    }
    //cout<<postfixexp<<endl;
}
void cout_Si(int i)
{
    cout<<"("<<i<<")";
    if(i>0&&i<=9)
        cout<<"  "<<setw(5);
    else if(i>=10&&i<=99)
        cout<<"  "<<setw(4);
    else
        cout<<setw(3);
    cout<<Si[i].op<<","<<Si[i].w1<<"   ,"<<Si[i].w2<<"   ,"<<Si[i].step<<endl;//输出判断语句第一条语句为真时

}
void Manage_if(int L,int R,int M)//L为表达式的左边，R为if的结束处，M代表else的结束处
{
    //cout<<"***************2\n";
    Si[Begin].op=Array[L+2];
    Si[Begin].w1=Array[L];
    Si[Begin].w2=Array[L+4];
    string yy="";
    //cout<<Begin<<endl;
    Num_Str(Begin+2,yy);
    yy+='\0';
    //cout<<yy<<endl;
    Si[Begin].step=yy;
    cout_Si(Begin++);
    //cout<<"("<<Begin++<<")"<<setw(5)<<"( "<<Array[L+2]<<","<<Array[L]<<","<<Array[L+4]<<Begin+1<<")"<<endl;//输出判断语句第一条语句为真时
    Si[Begin].op="J--";
    Si[Begin].w1="-";
    Si[Begin].w2="-";
    int m=Begin++;//记录表达式为假时的四元式
    L=L+10;
    while(L<R)//结果为真时的处理
    {
        string exp1="";
        while(Array[L][0]!=';')
        {
            exp1+=Array[L];
            L=L+2;
        }
        //cout<<exp1<<endl;
        Biaodashi(exp1);
        if(Array[L+2][0]=='}')
            break;
        else
            L=L+2;
    }


    Si[Begin].op="J-";//结果为真的语句执行完后要跳出去
    Si[Begin].w1="-";
    Si[Begin].w2="-";
    int nn=Begin++;
    yy="";
    Num_Str(Begin,yy);
    yy+='\0';
    //cout<<"Begin ="<<Begin<<"yy ="<<yy<<endl;
    Si[m].step=yy;//结果为真处理完就知道当结果为假时要跳到哪去
    L=L+8;
    while(Array[L][0]!='}')
    {
        string exp1="";
        while(Array[L][0]!=';')
        {
            exp1+=Array[L];
            L=L+2;
        }
        Biaodashi(exp1);
        if(Array[L+2][0]=='}')
            break;
        else
            L=L+2;
    }
    yy="";
    Num_Str(Begin,yy);
    yy+='\0';
    //cout<<"Begin ="<<Begin<<yy<<endl;
    Si[nn].step=yy;
    for(int i=m;i<Begin;i++)
        cout_Si(i);
}

void Manage_While(int l,int r)
{
    int i=l+4;
    int m=Begin;
    Si[Begin].op=Array[i+2];
    Si[Begin].w1=Array[i];
    Si[Begin].w2=Array[i+4];
    string mm="";
    Num_Str(Begin+2,mm);
    Si[Begin].step=mm;//while为真时
    cout_Si(Begin++);

    Si[Begin].op="J--";//while为假时
    Si[Begin].w1="-";
    Si[Begin].w2="-";
    m=Begin++;
    int L=i+10;
    while(Array[L][0]!='}')
    {
        string exp1="";
        while(Array[L][0]!=';')
        {
            exp1+=Array[L];
            L=L+2;
        }
        Biaodashi(exp1);
        if(Array[L+2][0]=='}')
            break;
        else
            L=L+2;
    }
    mm="";
    Num_Str(Begin,mm);
    Si[m].step=mm;
    for(i=m;i<Begin;i++)
        cout_Si(i);
}
void Expression()
{
    cout<<"四元式：\n";
    for(int i=10;i<Len;)
    {
        if(Array[i+1][0]=='1')//表示是关键字
        {
            //cout<<"***************3\n";
            switch (Array[i][0])
            {
                //cout<<"***************2\n";
            case 'i'://此时为int ,if
                if(Array[i][1]=='n')
                {

                    Si[Begin].op="int";
                    Si[Begin].w1="-";
                    Si[Begin].w2="-";
                    Si[Begin].step=Array[i+2];
                    //cout<<"("<<Begin++<<")"<<setw(5)<<"---,--,--,"<<Array[i+2]<<endl;//输出定义的第一条语句
                    cout_Si(Begin++);
                    i=i+6;
                    while(Array[i][0]!=';')
                    {
                        if(Array[i][0]==',')
                            i=i+2;
                        Si[Begin].op="int";
                        Si[Begin].w1="-";
                        Si[Begin].w2="-";
                        Si[Begin].step=Array[i];
                        //cout<<"("<<Begin++<<")"<<setw(5)<<"---,--,--,"<<Array[i+2]<<endl;
                        cout_Si(Begin++);
                        i=i+2;
                    }
                    i=i+2;
                }
                else
                {

                    int L=i+4,R,M,j;
                    for(j=i+6;Array[j][0]!='}';j++);
                    R=j-1;
                    for(j=j+6;Array[j][0]!='}';j++);
                    M=j-1;
                    Manage_if(L,R,M);//处理if语句
                    i=M+3;
                }
                break;
            case 'w':
                //cout<<"$$$$$$$$$$$$$$$$$$$$$$$$46\n";
                int j,r;
                for(j=i;Array[j][0]!='}';j++);
                r=j-1;
                //cout<<"$$$$$$$$$$$$$$$$$$$$$$1\n";
                Manage_While(i,r);
                //cout<<"$$$$$$$$$$$$$$$$$$$$$$2\n";
                i=j+2;
                break;
            case 'r':
                return ;
            }

        }
        else if(Array[i+1][0]=='2')//标识符
        {
            //cout<<"***************5";
            string exp1="";
            while(Array[i][0]!=';')
            {
                exp1+=Array[i];
                i=i+2;
            }
            int x=Begin;
            Biaodashi(exp1);
            for(int i=x;i<Begin;i++)
                cout_Si(i);
            i=i+2;
            //cout<<Array[i]<<endl;
        }
        //cout<<"!!!!!!!!!!!";
    }
}
/********************************将四元式写入文件***************/
void Write_tofile()
{
    FILE * fp;
    if((fp=fopen("四元式.txt","w"))==NULL)
    {
        cout<<"Failure to open 四元式.txt\n";
        exit(0);
    }
    fwrite(Si,sizeof(struct Siyuan),Begin-1,fp);
    fclose(fp);
}
/********************************将汇编程序写入文件***************/

void Write_file()
{
    FILE * fp;
    if((fp=fopen("汇编程序.txt","w"))==NULL)
    {
        cout<<"Failure to open 汇编程序.txt\n";
        exit(0);
    }
    fwrite(Goal,sizeof(struct Goal),Begin-1,fp);
    fclose(fp);
}
/****************************生成目标程序**********************/
void INITT(int x,string g1,string g2,string g3)
{
    Goal[start].step=x;
    Goal[start].G1=g1;
    Goal[start].G2=g2;
    Goal[start].G3=g3;
    start++;
}
///*************************字符串转化成数字*******************/
int StrtoNum(string ss)
{
    int num;
    stringstream s1(ss);
    s1>>num;
    return num;
}
/*************************数字转化成字符串*******************/
string NumtoStr(int x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}
void cout_G(int i)
{
    cout<<Goal[i].step<<" : "<<Goal[i].G1<<" "<<Goal[i].G2<<" "<<Goal[i].G3<<endl;
}
void Goal_Prog()
{
    cout<<"汇编程序:"<<endl;
    for(int i=0;i<Begin;i++)
    {
        switch (Si[i].op[0])
        {
        case 'i':
            INITT(END++,"DW",Si[i].step,"");
            cout_G(start-1);
            break;
        case '=':
            INITT(END++,"MOV",Si[i].step,Si[i].w1);
            cout_G(start-1);
            break;
        case '+':
            INITT(END++,"MOV","AX",Si[i].w2);
            cout_G(start-1);
            INITT(END++,"ADD","AX",Si[i].w1);
            cout_G(start-1);
            INITT(END++,"MOV",Si[i].step,"AX");
            cout_G(start-1);
            break;
        case '-':
            INITT(END++,"CMP",Si[i].w2,Si[i].w1);
            cout_G(start-1);
            END++;

            INITT(END,"JNC","",NumtoStr(END+3));
            cout_G(start-1);

            INITT(END++,"SBB",Si[i].w2,Si[i].w1);
            cout_G(start-1);

            INITT(END++,"JMP","",NumtoStr(END+2));
            cout_G(start-1);

            INITT(END++,"SUB",Si[i].w2,Si[i].w1);
            cout_G(start-1);
            break;
        case '*':
            INITT(END++,"MOV","AX",Si[i].w2);
            cout_G(start-1);
            INITT(END++,"IMUL","",Si[i].w1);
            cout_G(start-1);

            INITT(END++,"MOV",Si[i].step,"AX");
            cout_G(start-1);
        case '/':
            INITT(END++,"MOV","AX",Si[i].w2);
            cout_G(start-1);
            INITT(END++,"IDIV","",Si[i].w1);
            cout_G(start-1);
            INITT(END++,"MOV",Si[i].step,"AX");
            cout_G(start-1);
            break;
        case '%':
            INITT(END++,"MOV","AX",Si[i].w2);
            cout_G(start-1);
            INITT(END++,"IDIV","",Si[i].w1);
            cout_G(start-1);
            INITT(END++,"MOV",Si[i].step,"DX");
            cout_G(start-1);
            break;
        case '>':
            INITT(END++,"CMP",Si[i].w1,Si[i].w2);
            cout_G(start-1);
            break;
        case 'J':
            INITT(END++,"JC","",NumtoStr(END+StrtoNum(Si[i].step)-i));
            cout_G(start-1);
            break;
        }
    }
}
void function()
{
    char* s="1.txt";
    Read_file(s,getsym);//读取程序完毕
    length=getsym.size();
    getSym();//处理分离
    s="f1.txt";
    Read_filef1(s);
    Expression();
    Write_tofile();
    Goal_Prog();
    Write_file();
    //cout<<Begin<<endl;
    //cout<<"$$$$$$$$$$$$$4\n";
}
int main()
{
    function();
    return 0;
}

