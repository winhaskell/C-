// 使用STL中的next_permutation函数生成排列
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char res[] = "ABCD";
    do{
        puts(res);
    }while(next_permutation(res, res+4));
    return 0;
}



---------------------------------------------------



#include <bits/stdc++.h>
using namespace std;

int n;
char table[] = "ABCDEFGHIJK";
char res[1024];

void solve(int cur)
{
    if(cur == n){
        res[cur] = 0;
        puts(res);
        return ;
    }
    for(int i = 0; i < n; i++){
        bool ok = true;
        for(int j = 0; j < cur; j++)
            if(table[i] == res[j])
                ok = false;
        if(ok){
            res[cur] = table[i];
            solve(cur+1);
        }
    }
}


int main()
{
    while(cin >> n)
        solve(0);
    return 0;
}




---------------------------------------------------





#include <bits/stdc++.h>
using namespace std;

int n;
char res[] = "ABC";

void solve(int cur)
{
    if(cur == n){
        res[cur] = 0;
        puts(res);
        return ;
    }
    for(int j = cur; j < n; j++){
        swap(res[j], res[cur]);
        solve(cur+1);
        swap(res[j], res[cur]);
    }
}

int main()
{
    n = strlen(res);
    solve(0);
    return 0;
}
