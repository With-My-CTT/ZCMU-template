//���ֲ���

//lower_bound()���� 
lower_bound(a+begin,a+end,k) 
//���ص�һ�� ��ֵ ���ڵ��� k �ĵ�ַ,�����򷵻�end�ĵ�ַ  

//upper_bound()����
upper_bound(a+begin,a+end,k)
//���ص�һ�� ��ֵ ���� k �ĵ�ַ,�����򷵻�end�ĵ�ַ 

//һ��д�� 
int binarySearch(int nums[], int target) 
{ 
	int low = 0, high = nums.length-1; 
	while (low <= high) 
	{
		int mid = low + (high - low) / 2; 
		if (nums[mid] < target) 
		{ low = mid + 1; } 
		if (nums[mid] > target) 
		{ high = mid - 1; } 
		if (nums[mid] == target) 
		{ return mid; } 
	} 
	return low; 
}


