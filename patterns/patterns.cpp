#include <iostream>
using namespace std;

void p1(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void p2(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void p3(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << j+1 << " ";
        }
        cout << endl;
    }
}

void p4(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << i+1 << " ";
        }
        cout << endl;
    }
}

void p5(){
    for (int i = 5; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void p6(){
    for (int i = 5; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << j+1 << " ";
        }
        cout << endl;
    }
}

void p7(){
    int count = 1;
    for (int i = 5; i > 0; i--)
    {
        for (int j = 0; j < i-1; j++)
        {
            cout << "  ";
        }
        for (int k = 0; k < count; k++)
        {
            cout << "* ";
        }
        count +=2;
        cout << endl;
        
    }
}

void p8(){
    int count = 8;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < i+1; j++)
        {
            cout << "  ";
        }
        for (int k = 0; k <= count; k++)
        {
            cout << "* ";
        }
        count -=2;
        cout << endl;
        
    }
}

void p9(){
    p7();
    p8();
}

void p10(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << "* ";
            if (i>4)
            {
                break;
            }
        }
        cout << endl;
    }
    for (int i = 4; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void p11(){
    bool is_odd = true;
    int num;
    for (int i = 1; i <= 5; i++)
    {
        num = 1;
        if (i % 2 == 0)
        {
            num = 2;
        }

        for (int j = 1; j < i+1; j++)
        {
            if (num % 2 == 0 )
            {
                is_odd = false;
            }
            else
            {
                is_odd = true;
            }
            
            cout << is_odd << " ";
            num++;
        }
        cout << endl;
    }
}

void p12(){
    int count = 6;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << j+1 ;
        }
        for (int k = count; k > 0; k--)
        {
            cout << " ";
        }
        count-=2;
        
        for (int l = i; l > 0; l--)
        {
            cout << l;
        }
        cout << endl;
    }
}

void p13(){
    int count = 1;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}

void p14(){
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << char(j+65) << " ";
        }
        cout << endl;
    }
}

void p15(){
    for (int i = 5; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << char(j+65) << " ";
        }
        cout << endl;
    }
}

void p16(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << char(i+65) << " ";
        }
        cout << endl;
    }
}

void p17(){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5 - i - 1; j++)
        {
            cout << "  ";
        }

        char ch = 'A';
        int breakpoint = ((2*i)+1)/2;
        for (int j = 0; j < (i*2) + 1; j++)
        {
            cout << ch << " ";

            if (j < breakpoint)
            {
                ch++;
            }
            else ch--;

            // cout << "* ";
        }
        
        for (int j = 0; j < 5 - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }

}

void p18(){
    char ch = 'E';
    while (ch >= 'A')
    {
        for (char i = ch; i <= 'E'; i++)
        {
            cout << i << " ";
        }
        ch--;
        cout << endl;
        
    }
}

void p19(){

    int count1 = 1;
    for (int i = 5; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        for (int k = 1; k < count1; k++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        count1 +=2;
        cout << endl;
        
    }
    
    int count2 = 8;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < i+2; j++)
        {
            cout << "* ";
        }
        for (int k = 1; k <= count2; k++)
        {
            cout << "  ";
        }
        for (int j = 1; j < i+2; j++)
        {
            cout << "* ";
        }
        count2 -=2;
        cout << endl;
        
    }

}

void p20(){
    int count1 = 8;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*" ;
        }
        for (int k = count1; k > 0; k--)
        {
            cout << " ";
        }
        count1-=2;
        
        for (int l = i; l > 0; l--)
        {
            cout << "*";
        }
        cout << endl;
    }

    int count2 = 2;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 5; j > i; j--)
        {
            cout << "*" ;
        }
        for (int k = 0; k < count2; k++)
        {
            cout << " ";
        }
        count2+=2;
        
        for (int l = 5; l > i; l--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void p21(){
    int rows = 4;
    for (int i = 1; i < rows; i++)
    {
        if (i == 1)
        {
            cout << "* * * *\n";
            continue;
        }
        cout << "*     *\n";

        if (i == rows - 1 )
        {
            cout << "* * * *";
        }
    }
    
}

void p22(){
    cout << endl;
    
    int num = 4;
    for (int i = 0; i < num*2 - 1 ; i++)
    {
        for (int j = 0; j < num*2 - 1 ; j++)
        {
            int top = i;
            int left = j;
            int right = num*2 - 2 - j;
            int bottom = num*2 - 2 - i;

            cout << ( num - min(min(top, bottom), min(left, right)) ) << " ";

        }
        cout << endl;
    }
}


int main(int argc, char const *argv[])
{
    cout << endl;
    p1();
    cout << endl;
    p2();
    cout << endl;
    p3();
    cout << endl;
    p4();
    cout << endl;
    p5();
    cout << endl;
    p6();
    cout << endl;
    p7();
    cout << endl;
    p8();
    cout << endl;
    p9();
    cout << endl;
    p10();
    cout << endl;
    p11();
    cout << endl;
    p12();
    cout << endl;
    p13();
    cout << endl;
    p14();
    cout << endl;
    p15();
    cout << endl;
    p16();
    cout << endl;
    p17();
    cout << endl;
    p18();
    cout << endl;
    p19();
    cout << endl;
    p20();
    cout << endl;
    p21();
    cout << endl;
    p22();
    cout << endl;
    return 0;
}
