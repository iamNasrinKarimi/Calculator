#include <iostream>
#include <string>
#include <math.h>
using namespace std;
////system: windows 10     compiler:codeblocks

/////////////moteghayer haye global///////////////////////
int bozorgi=0;
string adad1,xadad="";
string adad2,yadad="";
string amaliat;
bool dorosti2=1,dorosti1=1;
bool manfi1=0,manfi2=0;
//////////////////////////////////////////////////////////






////////////////////////////////////////////////tafrigh////////////////////////////////////////////
string tafrigh(string adad1,string adad2)
{
    for(int i=adad1.size()-1; i>=0; i--)
    {
        xadad+=adad1[i];
    }
    for(int i=adad2.size()-1; i>=0; i--)
    {
        yadad+=adad2[i];
    }
    if(xadad.size()>yadad.size())
    {
        string t=xadad;
        xadad=yadad;
        yadad=t;
    }

    xadad.append(yadad.size()-xadad.size()+1,'0');
    string jam=xadad;
    string xjam="";
    int ex=0;
    yadad+='0';

//////////////////////////////////////////////////////mos va manfi///////////////////
    if(manfi1==0&&manfi2==1)
    {
        for(int i=0; i<yadad.size(); i++)
        {
            if(yadad[i]=='-')
                yadad[i]='0';
        }
        for(int i=0; i<yadad.size(); i++)
        {
            int ragham=(yadad[i]-48)+(xadad[i]-48)+ex;
            if(ragham>=10)
                ex=1;
            else
                ex=0;
            //cout<<ragham<<"\n";
            if(ragham==10 && (i!=(yadad.size()-1)))
            {
                jam[i]=48;
            }
            else
                jam[i]=(ragham%10)+48;
            //jam[i+1]=jam[i+1]+(ragham/10);
            //cout<<"*";
        }
        for(int i=jam.size()-1; i>=0; i--)
        {
            xjam+=jam[i];
        }

    }
    //cout<<xjam<<"\n"<<jam;
    //for(int i=0;i<jam.size()-1;i++){
    //   xjam+=jam[i];
    //cout<<"*";
    //}
    //cout<<xjam;
///////////////////////////////////////////////////////////manfi va mos///////////////////////////////
    else if(manfi1==1&&manfi2==0)
    {
        for(int i=0; i<yadad.size(); i++)
        {
            if(yadad[i]=='-')
                yadad[i]='0';
        }
        //cout<<xadad<<"\n";
        //cout<<yadad<<"\n";
        for(int i=0; i<yadad.size(); i++)
        {
            int ragham=(yadad[i]-48)+(xadad[i]-48)+ex;
            if(ragham>=10)
                ex=1;
            else
                ex=0;
            //cout<<ragham<<"\n";

            jam[i]=(ragham%10)+48;
            //jam[i+1]=jam[i+1]+(ragham/10);
            //cout<<"*";
        }
        //cout<<jam;
        //cout<<jam<<"\n";
        for(int i=jam.size(); i>=0; i--)
        {
            xjam+=jam[i];
        }
        int gg=(int)xjam[0];
        if(gg==0)
            xjam[0]='0';
        int xx=xjam.size();
        //cout<<xjam;
        for(int i=0; i<xx; i++)
        {
            // cout<<xjam[i]<<"\n";
            if(xjam[i]!='0')
            {
                xjam[i-1]='-';
                break;
            }
        }
        //cout<<"@@@@@@";
    }
/////////////////////////////////////yeki mos yeki manfi////////////////////////////////
    else
    {
        for(int i=0; i<adad2.size(); i++)
        {
            if(adad2[i]=='-')
                adad2[i]='0';
        }
        for(int i=0; i<adad1.size(); i++)
        {
            if(adad1[i]=='-')
                adad1[i]='0';
        }
        if(adad2.size()>adad1.size())
        {
            int c=adad2.size()-adad1.size();
            for(int i=0; i<c; i++)
            {
                adad1.insert(adad1.begin(),'0');
                //cout<<i<<"\n";
            }
        }
        else
        {
            int c=adad1.size()-adad2.size();
            for(int i=0; i<c; i++)
            {
                adad2.insert(adad2.begin(),'0');
                //cout<<i<<"\n";
            }
        }
        //cout<<adad1<<"\n";
        //cout<<adad2<<"\n";
        for(int i=0; i<adad1.size(); i++)
        {
            if(adad1[i]>adad2[i])
            {
                bozorgi =1;
                break;
            }
            if(adad2[i]>adad1[i])
            {
                bozorgi =2;
                break;
            }
        }

        //cout<<adad1<<"\n";
        //cout<<adad2<<"\n";
        string temp;
        int A=adad1.length(),B=adad2.length();

        if(adad1.length()<adad2.length())
        {
            temp=adad1;
            adad1=adad2;
            adad2=temp;
        }
        else if(adad1.length()==adad2.length())
        {

            if(adad2>adad1)
            {
                temp=adad1;
                adad1=adad2;
                adad2=temp;
            }

        }
        if(A>B)
        {
            for(int i=0; i<A-B; i++)
                adad2.insert(0,"0");
        }
        else if(B>A)
        {
            for(int i=0; i<B-A; i++)
                adad1.insert(0,"0");
        }
        for(int i=0; i<adad1.length(); i++)
        {
            xjam+="0";
        }
        int o;
        char t='0';
        bool op=0;
        for(int i=adad1.length()-1; i>=0; i--)
        {
            if(adad2[i]=='9'&&t=='1')
            {
                adad2[i]='0';
                op=1;
            }
            else if(t=='1')
            {
                adad2[i]+=1;
            }
            if(adad1[i]>=adad2[i])
            {
                o=adad1[i];
                o-=adad2[i];
                t='0';
                if(op==1)
                {
                    op=0;
                    t='1';
                }
            }
            else
            {
                o=10+adad1[i]-adad2[i];
                t='1';
            }
            xjam[i]=o+'0';

        }
        int pp=xjam.size();
        if((manfi1==0&&bozorgi==2)||(manfi2==1&&bozorgi==1))
        {
            if(xjam[0]!='0')
            {
                xjam.insert(xjam.begin(),'-');
            }
            else
            {
                for(int i=1; i<pp; i++)
                {
                    if(xjam[i]!='0')
                    {
                        xjam[i-1]='-';
                        break;
                    }
                }
            }

        }
    }
    //cout<<xjam<<"\n";

    //cout<<bozorgi<<"\n";
    int i,n=0;
    for(i=0; xjam[i]=='0'; i++)
    {
        n+=1;
    }
    xjam.erase(0,n);

    return xjam;

}
///////////////////////////////////////////////////////////jam////////////////////////////////////////////
string jam(string adad1,string adad2)
{

    for(int i=adad1.size()-1; i>=0; i--)
    {
        xadad+=adad1[i];
    }
    for(int i=adad2.size()-1; i>=0; i--)
    {
        yadad+=adad2[i];
    }
    // cout<<xadad<<"////"<<yadad;
    if(xadad.size()>yadad.size())
    {
        string t=xadad;
        xadad=yadad;
        yadad=t;
    }

    xadad.append(yadad.size()-xadad.size()+1,'0');
    string jam=xadad;
    string xjam="";
    int ex=0;
    // cout<<jam<<"\n";
    yadad+='0';
    //  cout<<yadad<<"\n";
    //   cout<<xadad<<"\n";
//////////////////////////////////////////////////////mos va mos///////////////////
    if(manfi1==0&&manfi2==0)
    {
        for(int i=0; i<yadad.size(); i++)
        {
            int ragham=(yadad[i]-48)+(xadad[i]-48)+ex;
            if(ragham>=10)
                ex=1;
            else
                ex=0;
            //cout<<ragham<<"\n";
            if(ragham==10 && (i!=(yadad.size()-1)))
            {
                jam[i]=48;
            }
            else
                jam[i]=(ragham%10)+48;
            //jam[i+1]=jam[i+1]+(ragham/10);
            //cout<<"*";
        }
        for(int i=jam.size()-1; i>=0; i--)
        {
            xjam+=jam[i];
        }

    }
    //cout<<xjam<<"\n"<<jam;
    //for(int i=0;i<jam.size()-1;i++){
    //   xjam+=jam[i]v;
    //cout<<"*";
    //}
    //cout<<xjam;
///////////////////////////////////////////////////////////manfi va manfi///////////////////////////////
    else if(manfi1&&manfi2)
    {
        for(int i=0; i<yadad.size(); i++)
        {
            if(yadad[i]=='-')
                yadad[i]='0';
        }
        for(int i=0; i<xadad.size(); i++)
        {
            if(xadad[i]=='-')
                xadad[i]='0';
        }
        //cout<<xadad<<"\n";
        //cout<<yadad<<"\n";
        for(int i=0; i<yadad.size(); i++)
        {
            int ragham=(yadad[i]-48)+(xadad[i]-48)+ex;
            if(ragham>=10)
                ex=1;
            else
                ex=0;
            //cout<<ragham<<"\n";

            jam[i]=(ragham%10)+48;
            //jam[i+1]=jam[i+1]+(ragham/10);
            //cout<<"*";
        }
        //cout<<jam;
        //cout<<jam<<"\n";
        for(int i=jam.size(); i>=0; i--)
        {
            xjam+=jam[i];
        }
        int gg=(int)xjam[0];
        if(gg==0)
            xjam[0]='0';
        int xx=xjam.size();
        //cout<<xjam;
        for(int i=0; i<xx; i++)
        {
            // cout<<xjam[i]<<"\n";
            if(xjam[i]!='0')
            {
                xjam[i-1]='-';
                break;
            }
        }
        //cout<<"@@@@@@";
    }
    /////////////////////////////////////yeki mos yeki man////////////////////////////////
    else
    {
        for(int i=0; i<adad2.size(); i++)
        {
            if(adad2[i]=='-')
                adad2[i]='0';
        }
        for(int i=0; i<adad1.size(); i++)
        {
            if(adad1[i]=='-')
                adad1[i]='0';
        }
        if(adad2.size()>adad1.size())
        {
            int c=adad2.size()-adad1.size();
            for(int i=0; i<c; i++)
            {
                adad1.insert(adad1.begin(),'0');
                //cout<<i<<"\n";
            }
        }
        else
        {
            int c=adad1.size()-adad2.size();
            for(int i=0; i<c; i++)
            {
                adad2.insert(adad2.begin(),'0');
                //cout<<i<<"\n";
            }
        }
        //cout<<adad1<<"\n";
        //cout<<adad2<<"\n";
        for(int i=0; i<adad1.size(); i++)
        {
            if(adad1[i]>adad2[i])
            {
                bozorgi =1;
                break;
            }
            if(adad2[i]>adad1[i])
            {
                bozorgi =2;
                break;
            }
        }

        //cout<<adad1<<"\n";
        //cout<<adad2<<"\n";
        string temp;
        int A=adad1.length(),B=adad2.length();

        if(adad1.length()<adad2.length())
        {
            temp=adad1;
            adad1=adad2;
            adad2=temp;
        }
        else if(adad1.length()==adad2.length())
        {

            if(adad2>adad1)
            {
                temp=adad1;
                adad1=adad2;
                adad2=temp;
            }

        }
        if(A>B)
        {
            for(int i=0; i<A-B; i++)
                adad2.insert(0,"0");
        }
        else if(B>A)
        {
            for(int i=0; i<B-A; i++)
                adad1.insert(0,"0");
        }
        for(int i=0; i<adad1.length(); i++)
        {
            xjam+="0";
        }
        int o;
        char t='0';
        bool op=0;
        for(int i=adad1.length()-1; i>=0; i--)
        {
            if(adad2[i]=='9'&&t=='1')
            {
                adad2[i]='0';
                op=1;
            }
            else if(t=='1')
            {
                adad2[i]+=1;
            }
            if(adad1[i]>=adad2[i])
            {
                o=adad1[i];
                o-=adad2[i];
                t='0';
                if(op==1)
                {
                    op=0;
                    t='1';
                }
            }
            else
            {
                o=10+adad1[i]-adad2[i];
                t='1';
            }
            xjam[i]=o+'0';

        }
        int pp=xjam.size();
        if((manfi1&&bozorgi==1)||(manfi2&&bozorgi==2))
        {
            for(int i=0; i<pp; i++)
            {
                if(xjam[i]!='0')
                {
                    xjam[i-1]='-';
                    break;
                }
            }


        }
        //cout<<xjam<<"\n";
    }
    int n=0;
    for(int i=0; xjam[i]=='0'; i++)
    {
        n+=1;
    }
    xjam.erase(0,n);

    return xjam;

}


string tafrigh1(string a,string b)
{
    string k,temp;
    if(adad1==adad2)
        k="0";
    int A=a.length(),B=b.length();
    if(k!="0"){
    if(a.length()<b.length())
    {
        temp=a;
        a=b;
        b=temp;
    }
    else if(a.length()==b.length())
    {

            if(b>a)
            {
                temp=a;
                a=b;
                b=temp;
            }

    }
    if(A>B)
    {
        for(int i=0;i<A-B;i++)
            b.insert(0,"0");
    }
    else if(B>A)
    {
        for(int i=0;i<B-A;i++)
            a.insert(0,"0");
    }
    for(int i=0;i<a.length();i++)
    {
        k+="0";
    }
    int s;
    char t='0';
    bool x=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        if(b[i]=='9'&&t=='1')
        {
            b[i]='0';
            x=1;
        }
        else if(t=='1')
        {
            b[i]+=1;
        }
        if(a[i]>=b[i])
        {
            s=a[i];
            s-=b[i];
            t='0';
            if(x==1)
                {
                    x=0;
                    t='1';
                }
        }
        else
        {
            s=10+a[i]-b[i];
            t='1';
        }
        k[i]=s+'0';
    }
 for(int i=0;k[i]=='0';i++)
    k.erase(0,1);
    }
    return k;
}


/////////////jam1/////////////
string jam1(string a,string b){
    string k;
    int A=a.length(),B=b.length();
    if(A>B)
    {
        for(int i=0;i<A-B;i++)
            b.insert(0,"0");
    }
    else if(B>A)
    {
        for(int i=0;i<B-A;i++)
            a.insert(0,"0");
    }
    for(int i=0;i<a.length()+1;i++)
    {
        k+="0";
    }
    int s;
    char t='0';
    for(int i=a.length()-1;i>=0;i--)
    {
        s=a[i]-48;
        s+=b[i]-48;
        s+=t-48;
        if(s>=10)
        {
            t='1';
            s=s%10;
        }
        else
            t='0';
        k[i+1]=s+48;
    }
    k[0]=t;
    int yt=0;
    for(yt=0;k[yt]=='0';yt++)
        ;
    k.assign(k,yt,k.length()-yt);

    return k;
}



    //////////zarb//////
string zarb(string adad1,string adad2){
    int c=0,d=0,i,j,k,b,z;
    string t="",y="",sum="",l="";
    bool manfi=0;
    if(adad1[0]=='-'&&adad2[0]=='-')
    {
        adad1.erase(0,1);
        adad2.erase(0,1);
        manfi=0;
    }
    if(adad1[0]=='-'&&adad2[0]!='-')
    {
        adad1.erase(0,1);
        manfi=1;
    }
    if(adad1[0]!='-'&&adad2[0]=='-')
    {
        adad2.erase(0,1);
        manfi=1;
    }

    if(adad2.size()<adad1.size())
    {
        string x=adad2;
        adad2=adad1;
        adad1=x;
    }
    for(i=adad1.size()-1; i>=0; i--)
    {
        for(j=adad2.size()-1; j>=0; j--)
        {
            k=((int)adad1[i]-48)*((int)adad2[j]-48)+c;
            if(k>=10&&(j!=0))
            {
                c=k/10;
                k=k%10+48;
                t=t+(char)k;
            }
            else if(k>=10&&(j==0))
            {
                b=k/10+48;
                k=k%10+48;
                t=t+(char)k;
                t=t+(char)b;
                c=0;
            }
            else
            {
                k=k+48;
                t=t+(char)k;
                c=0;
            }
        }
        y="";
        d+=1;
        for(z=t.size()-1; z>=0; z--)
            y+=t[z];
        y.append(d-1,'0');
        sum=jam1(sum,y);
        t="";

}
if(adad1=="0"||adad2=="0")
    sum="0";
if(manfi==1&&sum!="0"){
    sum.insert(0,"-");
}
return sum;
}

///////////////taghsim///////////////
    string taghsim(string adada1,string adad2){
    string f="",tagh="";
    int i,k=0,n=0;
    bool manfi=0;

    if(adad1[0]=='-'&&adad2[0]=='-')
    {
        adad1.erase(0,1);
        adad2.erase(0,1);
        manfi=0;
    }
    else if(adad1[0]=='-'&&adad2[0]!='-')
    {
        adad1.erase(0,1);
        manfi=1;
    }
    else if(adad1[0]!='-'&&adad2[0]=='-')
    {
        adad2.erase(0,1);
        manfi=1;
    }
    for(int j=0;adad1[j]=='0';j++){
       n+=1;
    }
    adad1.erase(0,n);
    n=0;
    for(int j=0;adad2[j]=='0';j++){
       n+=1;
    }
    adad2.erase(0,n);

    if(adad1.size()<adad2.size())
        tagh="0";
    else if(adad1.size()==adad2.size()&&adad1<adad2)
            tagh="0";
    else{
        for(i=0;i<adad2.size();i++)
            f=f+adad1[i];
        if(f<adad2){
            f="";
            for(i=0;i<=adad2.size();i++)
                f=f+adad1[i];

        }

        while(i<=adad1.size())
        {
            if(adad2.size()==0){
                tagh="tarif nashode";
                break;
            }
            if((f.size()==adad2.size()&&f<adad2)||f.size()<adad2.size()){
                k=0;
            }
            while(((f.size()==adad2.size())&&(adad2<f||f==adad2))||f.size()>adad2.size()){
                f=tafrigh1(f,adad2);
                k+=1;
            }
            tagh=tagh+char(k+48);
            k=0;

            f=f+adad1[i];
            i++;


            if(f[0]=='0')
                f.erase(0,1);

        }
    }

    if(manfi==1&&tagh!="0")
        tagh.insert(0,"-");

return tagh;
}



void aks(string &adad)
{
    char t;
    int s=adad.size();
    for(int i=0;i<s/2;i++)
    {
        t=adad[i];
        adad[i]=adad[s-i-1];
        adad[s-i-1]=t;
    }
}
void virayesh(string &a,string &b)
{
    if(a.size()>b.size())
        b.append(a.size()-b.size(),'0');
    else
        a.append(b.size()-a.size(),'0');
}
void tashih(string &adad)
{
    int i;
    for(i=adad.size()-1;adad[i]=='0';i--);
    i++;
    adad.erase(i,adad.size()-i);
}
bool alamat(string &a)
{
    if(a[0]=='-')
    {
        a.erase(0,1);
        return 1;
    }
    else
        return 0;
}
int moqayeseh(string a,string b)
{
    virayesh(a,b);
    for(int i=a.size()-1;i>=0;i--)
    {
        if(int(a[i])>int(b[i]))
            return 1;
        if(int(b[i])>int(a[i]))
            return 2;
    }
    return 0;
}
string majmo(string a,string b)
{
    string c;
    int cary=0;
    virayesh(a,b);
    for(int i=0;i<a.size();i++)
    {
        cary+=int(a[i])+int(b[i])-96;
        c.append(1,char(48+(cary%10)));
        cary/=10;
    }
    if(cary!=0)
    {
        c.append(1,char(48+cary));
    }
    return c;
}
string tafriq(string a,string b)
{
    string c;
    int cary=0;
    virayesh(a,b);
    c.append(a.size(),'0');
    for(int i=0;i<a.size();i++)
    {
        cary+=(a[i]-b[i]);
        if(cary<0)
        {
            c[i]=char(58+cary);
            cary=-1;
        }
        else
        {
            c[i]=char(48+cary);
            cary=0;
        }
    }
    tashih(c);
    return c;
}
string zarb1(string a,string b)
{
    string c;
    int cary=0;
    virayesh(a,b);
    for(int i=0;i<a.size();i++)
    {
        for(int j=0,k=i;j<=i;j++,k--)
            cary+=((int(a[j])-48)*(int(b[k])-48));
        c.append(1,char(48+(cary%10)));
        cary/=10;
    }
    for(int i=a.size();i<2*a.size()-1;i++)
    {
        for(int j=a.size()-1,k=i-j;k<a.size();j--,k++)
            cary+=((int(a[j])-48)*(int(b[k])-48));
        c.append(1,char(48+(cary%10)));
        cary/=10;
    }
    if(cary>0)
        c.append(1,char(48+(cary%10)));
    tashih(c);
    return c;
}

void radikal(string adad)
{
    string gam,jazr="0",majzor;
    int n,s=0;
    cout<<"raqam ashar=";
    cin>>n;
    if(adad[0]=='-')
        cout<<"error";
    else{
    for(int j=0;adad[j]=='0';j++){
       s+=1;
    }
    adad.erase(0,s);

    for(int i=0;i<n;i++)
        adad="00"+adad;;
    for(int i=(adad.size()-1)/2;i>=0 && moqayeseh(majzor,adad)!=0;i--)
    {
        gam.append(i,'0');
        gam.append(1,'1');
        while(moqayeseh(adad,majzor)<2)
        {
            jazr=majmo(jazr,gam);
            majzor=zarb1(jazr,jazr);
        }
        jazr=tafriq(jazr,gam);
        majzor=zarb1(jazr,jazr);
        gam.erase(0,gam.size());
    }
    if(n==0)
    {
        aks(jazr);
        cout<<"="<<endl<<jazr;
    }
    else
    {
        jazr.append(1,'0');
        for(int i=jazr.size()-1;i>n;i--)
            jazr[i]=jazr[i-1];
        jazr[n]='.';
        aks(jazr);
        tashih(jazr);
        cout<<"="<<endl<<jazr;
    }
    }

}
string tavan(string num1,string n)
{
    string hasel="1",i="0",one="1";
    bool adad=alamat(num1),manfi=0;
    aks(num1);
    tashih(num1);
    if(n[0]=='-'){
            hasel="error";
            manfi=1;
    }
    if(manfi==0){
    aks(n);
    tashih(n);
    if(n=="5.")
    {
        radikal(num1);
    }
    else
    {
        while(moqayeseh(n,i)!=0)
        {
            i=majmo(i,one);
            hasel=zarb1(hasel,num1);
        }
        aks(hasel);
        if(adad==0 || int(n[0])%2==0)
            ;
        else
            hasel.insert(0,"0");
    }
    }
    return hasel;
}


string baghi(string adad1,string adad2){
    string f="",tagh="";
    int i,k=0,n=0;
    bool manfi=0;

    if(adad1[0]=='-'||adad2[0]=='-')
    {
        cout<<"error";
        manfi=1;
    }


    for(int j=0;adad1[j]=='0';j++){
       n+=1;
    }
    adad1.erase(0,n);
    n=0;
    for(int j=0;adad2[j]=='0';j++){
       n+=1;
    }
    adad2.erase(0,n);
if(manfi==0){
    if(adad1.size()<adad2.size())
        f="0";
    else if(adad1.size()==adad2.size()&&adad1<adad2)
            f="0";
    else{
        for(i=0;i<adad2.size();i++)
            f=f+adad1[i];
        if(f<adad2){
            f="";
            for(i=0;i<=adad2.size();i++)
                f=f+adad1[i];

        }

        while(i<=adad1.size())
        {
            if(adad2.size()==0){
                f="tarif nashode";
                break;
            }
            while(((f.size()==adad2.size())&&(adad2<f||f==adad2))||f.size()>adad2.size()){
                f=tafrigh1(f,adad2);

            }

            f=f+adad1[i];
            i++;

            if(f[0]=='0')
                f.erase(0,1);

        }
    }
}
    if(f.size()==1)
        f="0";
    return f;
}
double radian(string DEG){
    string r;
    double rad,pi=3.14159265358979323846;
    int d=1,a,b=0;
    r="360";
    if((DEG.size()>3)||(DEG.size()==3&&(r<DEG||r==DEG))){
        DEG=baghi(DEG,r);
        DEG.erase(DEG.size()-1,1);
    }
    for(int i=DEG.size()-1;i>=0;i--){
        a=((int)DEG[i]-48)*d;
        b+=a;
        d*=10;
    }
    rad=b*pi/180;
return rad;
}
float SIN(string a){
    bool manfi=0;
    float x;
    int n=0;
    if(a[0]=='-'){
        a.erase(0,1);
        manfi=1;
    }
     for(int j=0;a[j]=='0';j++){
       n+=1;
    }
    a.erase(0,n);

    double k;
    k=radian(a);
    x=sin(k);
    if(manfi==1)
        x=-1*x;
    cout<<std::fixed;
    cout.precision(6);
    return x;

}
float COS(string a){
    int n=0;
    if(a[0]=='-')
        a.erase(0,1);
     for(int j=0;a[j]=='0';j++){
       n+=1;
    }
    a.erase(0,n);
    double k;
    float x;
    k=radian(a);
    x=cos(k);
    cout<<std::fixed;
    cout.precision(4);
    return x;
}

float TAN(string a){
    bool manfi=0;
    int n=0;
    if(a[0]=='-'){
        a.erase(0,1);
        manfi=1;
    }
     for(int j=0;a[j]=='0';j++){
       n+=1;
    }
    a.erase(0,n);
    double k;
    float x;
    k=radian(a);
    x=tan(k);
    cout<<std::fixed;
    cout.precision(3);
    if(manfi==1)
        x=-1*x;
    return x;
}
void display(void){
   cout<<"***adad aval ra vared konid*** :";
    getline(cin,adad1);
////////////////////////////////////
    cout<<"*1*jam => (+)"<<endl<<"*2*tafrigh =>> (-)"<<endl<<"*3*zarb =>> (*)"<<endl<<"*4*taghsim =>> (/)"<<endl<<"*5*tavan =>> (^)"<<endl<<"*6*jazzr =>> (#)"<<endl<<"*7*sinus =>> (sin)"<<endl<<"*8*cosinus =>> (cos)"<<endl<<"*9*tangant =>>(tan)"<<endl<<"*10*baghimande =>> (%)"<<endl;
    getline(cin,amaliat);
        if(amaliat=="*"||amaliat=="+"||amaliat=="-"||amaliat=="/"||amaliat=="%"||amaliat=="^"){
            cout<<"\n"<<"***adad dovom ra vared konid***:";
            getline(cin,adad2);
        }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
for(int i=0; i<adad1.size(); i++)
    {
        int askinumber1=(int)adad1[i];
        if(!(askinumber1>=48&&askinumber1<=57))
        {
            if(adad1[i]=='-'&&i==0)
            {
                manfi1=1;
                dorosti1=1;
                //adad1[i]<<=1;
            }
            else
            {
                dorosti1=0;
            }
        }
        else
        {
            dorosti1=1;
        }
        if(dorosti1==0)
            break;
    }
/////////////////////////////////////////////////
for(int i=0; i<adad2.size(); i++)
    {
        int askinumber2=(int)adad2[i];
        if(!(askinumber2>=48&&askinumber2<=57))
        {
            if(adad2[i]=='-'&&i==0)
            {
                manfi2=1;
                dorosti2=1;
                //adad1[i]<<=1;
            }
            else
            {
                dorosti2=0;
            }
        }
        else
        {
            dorosti2=1;
        }
        if(dorosti2==0)
            break;
    }






if(dorosti1==1&&dorosti2==1){
    if(amaliat=="+")
        cout<<"="<<jam(adad1,adad2);
    else if(amaliat=="-")
        cout<<"="<<tafrigh(adad1,adad2);
    else if(amaliat=="*")
        cout<<"="<<zarb(adad1,adad2);
    else if(amaliat=="/")
        cout<<"="<<taghsim(adad1,adad2);
    else if(amaliat=="^")
        cout<<"="<<tavan(adad1,adad2);
    else if(amaliat=="%")
        cout<<"="<<baghi(adad1,adad2);
    else if(amaliat=="sin")
        cout<<"="<<SIN(adad1);
    else if(amaliat=="cos")
        cout<<"="<<COS(adad1);
    else if(amaliat=="tan")
        cout<<"="<<TAN(adad1);
    else if(amaliat=="#")
    {
       cout<<"=";
       radikal(adad1);
    }
    else cout<<"erorr<<faghat az amalgarha estefade kon!!!>> ";
}
else{
    cout<<"erorr!!!";
}

}



///////////////////////////////////payane tavabe/////////////////////////////
int main()
{
display();
return 0;

}
