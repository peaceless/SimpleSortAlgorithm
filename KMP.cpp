//ʹ��Kmp�㷨����ģʽƥ��
//ʱ�临�Ӷ�ΪO(m+n)


//next����ֵ���㷨����
void get_next(char T[],int next[]) {
	i = 1;
	next[1] = 0;
	j = 0;
	while(i<=T[0]) {	//T[0]���ڱ����ַ������� 
		if(j==0 || T[i] == t[j]){
			++i;++j;next[i]=j;
		}
		else j = next[j];
	}
} 

//�������Ƚ�
int KMP(char S[],chat T[],int next[],int pos){
	//����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨
	//���У�T�ǿգ�1<=pos<=strlen(s)
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
