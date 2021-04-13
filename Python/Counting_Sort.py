from collections import defaultdict
def Counting_Sort(array):
	count = defaultdict(int)
	min_=999999999
	max_=-99999999
	for i in array:
		if(i < min_):
		    min_=i
		if(i > max_):
		    max_=i
		count[i] += 1
	result = []
	for j in range(min_,max_+1):
		result += [j]* count[j]
	return result

