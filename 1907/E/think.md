# Think of CF1907E

考虑到$n \le 10^7$，遂考虑$O(n)$算法。

那么可以考虑固定一个数$a$，配合 $n$ 来确定 $b$ 和  $c$。

> 三元组中数字的顺序不同视为不同的三元组。

更加印证了要枚举一个，而且题目标签里面写的有“brute force”，很好啊。

先考虑三重循环的算法，再考虑去优化

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
int cnt;
int digsum(int x){
	int sum = 0;
	while(x){
		sum += x%10;
		x /= 10;
	}
	return sum;
}

void work(){
	cin>>n;
	cnt = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;i+j<=n;j++){
			for(int k=0;i+j+k<=n;k++){
				if(i+j+k == n && digsum(i) + digsum(j) + digsum(k) == digsum(n)){
					cnt++;
				}
			}
		}
	}
	cout<<cnt<<endl<<endl;
}


signed main(){
	cin>>T;
	while(T--){
		work();
	}
}
```

这个代码是正确的，只不过会超时。

我们可以考虑到 $i+j+k = n$ 且 $i$ 和 $j$ 是固定的，我们就可以求出 $k$ ，进化为两重循环 ，就像 百钱买百鸡 一样。

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
int cnt;
int digsum(int x){
	int sum = 0;
	while(x){
		sum += x%10;
		x /= 10;
	}
	return sum;
}

void work(){
	cin>>n;
	cnt = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;i+j<=n;j++){
			int k = n-i-j;
			if(digsum(i) + digsum(j) + digsum(k) == digsum(n)){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
}


signed main(){
	cin>>T;
	while(T--){
		work();
	}
}
```
很好，但样例都会超时，考虑继续优化。这道题长得很像百钱买百鸡呀，几乎一模一样，我们延续思路，解——方——程。

我们的目标：解出来一个不定方程，然后枚举出来其中一个，求出另一个。

~~这不就是百钱买百鸡一模一样的吗？~~

先 $O(1e7)$ 预处理出来所有 $digsum$ 

$$ x + y + n - x - y = n $$

$$ dig[x] + dig[y] + dig[n - x - y] = dig[n] $$