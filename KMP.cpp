//使用Kmp算法进行模式匹配
//时间复杂度为O(m+n)


//next函数值的算法如下
void get_next(char T[],int next[]) {
	i = 1;
	next[1] = 0;
	j = 0;
	while(i<=T[0]) {	//T[0]用于保存字符串长度 
		if(j==0 || T[i] == t[j]){
			++i;++j;next[i]=j;
		}
		else j = next[j];
	}
} 

//与主串比较
int KMP(char S[],chat T[],int next[],int pos){
	//利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
	//其中，T非空，1<=pos<=strlen(s)
	i = pos;
	j = 1;
	while(i<=S[0] && j<=T[0]){
		if(j == 0 || S[i] == T[j]){
			++i;++j;
		} else j = next[j];
	} 
	if(j > T[0]) return i - T[0];
	else return 0;
} 
