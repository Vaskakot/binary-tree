/*Эта программа совмещает в себе оба дерева*/
#include <iostream>

using namespace std;
template <class ecelop>
class Tree
{
private:
    struct Plank
    {
        ecelop data;
        Plank*left, *right;
    };
    typedef Plank* Branch;
    Branch Root;
    Branch Create(ecelop x)
    {
        Branch b=new Plank;
        b->data = x;
        b->left = NULL;
        b->left = NULL;
    }
    void Add(Branch c, Branch &Root)
    {
        if(Root == NULL)Root = c;
        else
        {
            if(c->data > Root->data && Root->right==NULL)Root->right = c;
            if(c->data < Root->data && Root->left==NULL)Root->left = c;
            if(c->data > Root->data)Add(c, Root->right);
            if(c->data < Root->data)Add(c, Root->left);
        }
    }
    void Delete(ecelop x, Branch &b)
    {
        if(b)
        {
            if(x>b->data)Delete(x, b->right);
            if(x<b->data)Delete(x, b->left);
            else
            {
                if(b->left==NULL&&b->right==NULL)
                {
                    Branch c = Root;
                    while(c->left!=b&&c->right!=b)
                    {
                        if(c->data<x)c=c->left;
                        else c=c->right;
                    }
                    c->data = b->data;
                    if(c->left==b)c->left =NULL;
                    else c->right = NULL;
                    delete c;
                    b->data = 0;
                    delete b;
                }
                else if(b->left==NULL^b->right == NULL)
                {
                    Branch c = Root;
                    while(c->left!=b&&c->right!=b)
                    {
                        if(c->data<x)c=c->left;
                        else c=c->right;
                    }
                    c->data = b->data;
                    c->left = b->left;
                    c->right = b->right;
                    delete c;
                    b->data = 0;
                    delete b;
                }
                else
                {
                    if(b->right->left == NULL)
                    {
                        Branch c = Root;
                        while(c->left!=b&&c->right!=b)
                        {
                            if(c->data<x)c=c->left;
                            else c=c->right;
                        }
                        c->data = b->data;
                        c->left = b->left;
                        c->right = b->right;
                        delete c;
                        b->data = 0;
                        delete b;
                    }
                    else
                    {
                        Branch c = b;
                        while(c->left)c=c->left;
                        b->data = c->data;
                        c->data = 0;
                        delete c;
                    }
                }
            }
        }
    }
    void DELETE(Branch b)
    {
        DELETE(b->left);
        DELETE(b->right);
        Delete(b->data, b);
    }
    void Build(string s, Branch b, int j)
    {
        while(j)
        {
            b=Create(s[j]);
            if(s[j]>='0'&&s[j]<='9')
            {
                b->left = NULL;
                b->right = NULL;
            }
            else
            {
                j--;
                Build(s, b->right,j);
                j--;
                Build(s, b->left, j);
            }
        }
    }
    float Soulver(Branch b)
    {
        if(b->data>='0'&&b->data<='9')return b->data;
        else
        {
            if(b->data=='+')return (Soulver(b->left)+Soulver(b->right));
            if(b->data=='-')return (Soulver(b->left)-Soulver(b->right));
            if(b->data=='*')return (Soulver(b->left)*Soulver(b->right));
            if(b->data=='/')return (Soulver(b->left)/Soulver(b->right));
        }
    }
    int counter = 0;
public:
    Tree()
    {
        Root = NULL;
    }
    Branch Groot()
    {
        return Root;
    }
    void AddPlank(ecelop x)
    {
        Branch c = Create(x);
    }
    void PrintUp(Branch b)
    {
        if(b->left)PrintUp(b->left);
        cout<<Root->data<<" ";
        if(b->right)PrintUp(b->right);
    }
    void PrintDown (Branch b)
    {
         if(b->right)PrintDown(b->right);
         cout<<b->data<<" ";
         if(b->left)PrintDown(b->left);
    }
    void PrintTier (Branch b)
    {
        if(b->right){
            counter++;
            PrintTier(b->right);}
        for(int i=0; i<=counter; i++)cout<<"    ";
        cout<<b->data<<endl;
        if(b->left)
        {
            counter ++;
            PrintTier(b->left);
        }
    }
    void DeletePlank (ecelop x)
    {
        Delete(x, Root);
    }
    void BuildTree(string s)
    {
        cout<<"WARNING! Your tree must be char type to run this function"<<endl;
        Build(s, Root,s.size());
    }
    void PrintPre(Branch b)
    {
        cout<<"WARNING! This function is operational only with tree calculator. You need to use BuildTree before that"<<endl;
        cout<<b->data<<" ";
        if(b->left)PrintPre(b->left);
        if(b->right)PrintPre(b->right);
    }
    void PrintPost(Branch b)
    {
        cout<<"WARNING! This function is operational only with tree calculator. You need to use BuildTree before that"<<endl;
        if(b->left)PrintPost(b->left);
        if(b->right)PrintPost(b->right);
        cout<<b->data<<" ";
    }
    void PrintIn(Branch b)
    {
        cout<<"WARNING! This function is operational only with tree calculator. You need to use BuildTree before that"<<endl;
        if(b->data<'0'||b->data>'9')cout<<"(";
        if(b->left)PrintIn(b->left);
        cout<<Root->data<<" ";
        if(b->right)PrintIn(b->right);
        if(b->data<'0'||b->data>'9')cout<<"(";
    }
    float Solve ()
    {
        cout<<"WARNING! This function is operational only with tree calculator. You need to use BuildTree before that"<<endl;
        return Soulver(Root);
    }
    ~Tree()
    {
        if(Root)
        {
            DELETE(Root);
        }
    }
};
