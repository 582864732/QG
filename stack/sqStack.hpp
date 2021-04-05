#ifndef SQSTACK_H_
#define SQSTACK_H_

template<typename Elemtype>
class sqStack
{
private:
	int max_len;
	int len;
	Elemtype* stack;
public:
	sqStack(int l)
	{
		len = 0;
		max_len = l;
		stack = new Elemtype[l];
	}
	~sqStack(){ delete[] stack; }
	bool isEmpty() { return len == 0; }
	bool getTopStack(Elemtype&value)
	{
		if (len == 0) return false;
		value = stack[len - 1];
		return true;
	}
	void clear() { len = 0; }
	int length() { return len; }
	bool push(Elemtype data)
	{
		if (len == max_len) return false;
		len++;
		stack[len - 1] = data;
		return true;
	}
	bool pop(Elemtype *value=nullptr)
	{
		if (len == 0) return false;
		if (value != nullptr) *value = stack[len - 1];
		len--;
		return true;
	}
};
#endif // !SQSTACK_H_

