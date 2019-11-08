
// How Many Pieces of Land? �����طָ
// PC/UVa IDs: 110602/10213, Popularity: B, Success rate: average Level: 2
// Verdict: Accepted
// Submission Date: 2011-06-01
// UVa Run Time: 0.888s
//
// ��Ȩ���У�C��2011�����metaphysis # yeah dot net
//
// һ��Բ��Բ�� n ��������������֣��ܵõ�������������� 1 + C(n, 2) + C(n, 4)������ɲμ�
// ά����ҳ http://en.wikipedia.org/wiki/Dividing_a_circle_into_areas ���Լ�
// http://www.arbelos.co.uk/Papers/Chords-regions.pdf ��ʵ�����Ǵ����������������⡣
// ����ʵ����һ���������������㣬ʹ�� STL �е� vector ����ʾ��������λ����λ����λ��ֵ��ʾ��
// ���ַ�����int�ͱ�ʾ�Ĵ���ת��Ϊ��̬�����ʾ�Ĵ�������ʵ�ֱȽϡ��ӡ������ˡ����������㣬
// ������������������δȷ�ж��壬���Խ�һ�����ƣ�����һЩ�쳣���ʹ���ܹ�����ͨ�á�Ϊ�˽���
// ���㣬�����ز�������ʱ��ʹ���˴�ֵ��ʽ����Ҫ�����ã���Ҫע���ڼ���ʱ��ԭ��Ӧ�������ķ�
// ��λ��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define PLUS 	1	// ������
#define MINUS 	-1	// ������

// �����ࡣ
class integer
{
	friend ostream& operator<<(ostream&, const integer&);
	friend istream& operator>>(istream&, integer&);

	friend int compare(const integer, const integer);
	friend bool operator<(const integer, const integer);
	friend bool operator<=(const integer, const integer);

	friend integer operator<<(integer, int);

	friend integer operator+(integer, integer);
	friend integer operator-(integer, integer);
	friend integer operator*(integer, integer);
	friend integer operator/(integer, integer);
	friend integer operator^(integer, int);

public:
	integer() { };

	integer(int a)
	{
		signbit = (a >= 0 ? PLUS : MINUS);
		a = abs(a);
		while (a)
		{
			digits.push_back(a % 10);
			a /= 10;
		}
	};

	~integer() { };

	void zero_justify(void);

private:
	// ��ʾ�����Ľṹ����λ����λ����λ��˳���š��洢������λֵ����������λ���ַ�ֵ��
	// ���� 1 �� ASCII ��Ϊ 1 ���ַ��������� ��1�� ����ʾ��
	vector < char > digits;	// �����λֵ��
	int signbit;		// ����λ��
};

integer operator+(integer, integer);
integer operator-(integer, integer);

// �����������<<��
ostream& operator<<(ostream& os, const integer& n)
{
	// ��Ϊ��Ȼ��ʱ���������+���š�
	os << (n.signbit > 0 ? "" : "-");
	for (int i = n.digits.size() - 1; i >= 0; i--)
		// ��ŵ�����λֵ�����ʱҪת��Ϊ��λ���ַ�ֵ��
		os << (char)('0' + n.digits[i]);
	return os;
}

// �����������>>��
istream& operator>>(istream& in, integer& n)
{
	// �����ʾ���������ַ�����
	string s;
	in >> s;

	if (s.length() == 0)
	{
		// ������Ϊ0����ʾ�������һ�����ַ�����Ӧ��Ҫ���������ʾ�������ڱ�����˵����
		// ��������������ʲ����ǡ���Ҫ���ƣ���Ҫ��һ��������������
	}

	// �ڽ���֮ǰ����Ӧ�жϸ��ַ����Ƿ���һ���Ϸ��Ĵ�����ʾ������ʼһλΪ����λ��Ϊ��+����
	// ��-������������+�����Ժ��ԣ�����Ӧ��ȫ���������ַ����Ҳ�����ǰ��0�����ڱ��ⲻ���ڴ�����
	// �����ʲ����ǣ���Ҫ�������һ��������������

	// ��������λ��
	if (isdigit(s[0]))
		n.signbit = PLUS;
	else
	{
		n.signbit = (s[0] == '+' ? PLUS : MINUS);
		s.erase(s.begin());
	}

	// ��������λ���ӵ�λ����λ����ڶ�̬�����С�
	n.digits.clear();
	for (int i = s.length() - 1; i >= 0; i--)
		n.digits.push_back((char)(s[i] - '0'));

	return in;
}

// �Ƴ��������������ǰ��0��
void integer::zero_justify(void)
{
	for (int i = digits.size() - 1; i >= 1; i--)
		if (digits[i] == 0)
			digits.erase(digits.begin() + i);
		else
			break;

	if (digits.size() == 1 && digits[0] == 0)
		signbit = PLUS;
}

// �Ƚ��������Ĵ�С������ȣ����� 0���� a ���� b������ 1���� a С�� b������ -1��
int compare(const integer a, const integer b)
{
	// �� a Ϊ����b Ϊ�������� a ���� b��
	if (a.signbit == PLUS && b.signbit == MINUS)
		return PLUS;

	// �� a Ϊ����b Ϊ������ a С�� b��
	if (a.signbit == MINUS && b.signbit == PLUS)
		return MINUS;

	// ������������ͬ���� a ����λ���ȴ��� b ����λ���ȣ��� a Ϊ���������� a ���� b���� a
	// Ϊ�������� a С�� b���� a �ķ���λ����1��Ϊ������ؼ��ɡ�
	if (a.digits.size() > b.digits.size())
		return PLUS * a.signbit;

	// ������������ͬ����a����λ����С��b����λ���ȣ��� a Ϊ�������� a С�� b���� a Ϊ������
	// �� a ���� b���� a �ķ���λ���� -1 ��Ϊ������ؼ��ɡ�
	if (a.digits.size() < b.digits.size())
		return MINUS * a.signbit;

	// ����������λ������ȣ�������ȣ���ӵ�λ����λ����Ƚ���λֵ�Ĵ�С��
	int marker = a.digits.size() - 1;
	while (marker >= 0)
	{
		if (a.digits[marker] > b.digits[marker])
			return PLUS * a.signbit;

		if (a.digits[marker] < b.digits[marker])
			return MINUS * a.signbit;

		marker--;
	}

	return 0;
}

// С�ڱȽϷ���
bool operator<(const integer a, const integer b)
{
	return compare(a, b) < 0;
}

// С�ڵ��ڱȽϷ���
bool operator<=(const integer a, const integer b)
{
	return compare(a, b) <= 0;
}

// ���Ʋ�����b ��ʾ���Ƶ�λ�������� a ���� 10^b��
integer operator<<(integer a, int b)
{
	integer c = a;

	// �� a ���� 0������λ����Ϊ 0��
	if (a.digits.size() == 1 && a.digits[0] == 0)
		return c;

	// �����ƶ� b λ���൱������λ����ǰ���� b �� 0��
	for (int i = 0; i < b; i++)
		c.digits.insert(c.digits.begin(), (char)(0));

	return c;
}

// �ӷ����㡣�ӵ�λ����λ���У�ÿһλ��Ӳ����Ľ�λ���λ���ݣ�ע�⸺���Ĵ���������Ӧ��
// ת��Ϊ�������򻯲�����
integer operator+(integer a, integer b)
{
	integer c;

	// ��������λ��ȣ������շ���λ��ԭ���ļ�������λ��ͬ��
	if (a.signbit == b.signbit)
		c.signbit = a.signbit;
	else
	{
		// ����������Ϊһ��һ��������ת��Ϊ����������
		if (a.signbit == MINUS)
		{
			a.signbit = PLUS;
			c = b - a;
		}
		else
		{
			b.signbit = PLUS;
			c = a - b;
		}

		return c;
	}

	// �Ӷ�̬����Ŀ�ʼ����λ��ʼ��ӣ�����ǰ��λ������еĻ���
	int carry = 0;		// ��λ��
	int maxsize = max(a.digits.size(), b.digits.size());
	int marker = 0;

	// Ϊ�������ǰ�� 0����ʹ����λ��ͬ�����ڼ��㡣
	while (a.digits.size() < maxsize)
		a.digits.push_back(char(0));
	while (b.digits.size() < maxsize)
		b.digits.push_back(char(0));

	// ��λ��ӡ�
	while (marker < maxsize)
	{
		int t = a.digits[marker] + b.digits[marker] + carry;
		carry = t / 10;
		c.digits.push_back((char)(t % 10));

		marker++;
	}

	// �����һ�ν�λΪ 1�����������λ�� 1��
	if (carry)
		c.digits.push_back((char)(1));

	c.zero_justify();

	return c;
}

// ������Ϊ�˱�֤��λ�ܹ��ɹ���ֹ�����ȷ����������С�ڼ�����ͬ���������ʵ����ת��Ϊ�ӷ����򻯲�����
integer operator-(integer a, integer b)
{
	integer c;

	// ��ĳһ����Ϊ����ʱ��ת��Ϊ�ӷ���
	if (a.signbit == MINUS || b.signbit == MINUS)
	{
		b.signbit = MINUS * b.signbit;
		c = a + b;

		return c;
	}

	// ������Ϊ�������� a < b��������֤���������ڼ�����
	if (a < b)
	{
		c = b - a;
		c.signbit = MINUS;

		return c;
	}
	else
		c.signbit = PLUS;

	int borrow = 0;		// ��λ��
	int maxsize = a.digits.size();	// ���������ڼ�����
	int marker = 0;		// ��������

	// Ϊ�������ǰ�� 0�����ڼ��㡣��Ϊ��ǰ�Ѿ�ʹ�� a > b �� a �� b ��Ϊ������
	while (b.digits.size() < maxsize)
		b.digits.push_back(char(0));

	// �ӵ�λ��ʼ��λ��������������λ��λ��
	while (marker < maxsize)
	{
		int v = a.digits[marker] - borrow - b.digits[marker];
		if (v < 0)
		{
			v += 10;
			borrow = 1;
		}
		else
			borrow = 0;

		c.digits.push_back((char)(v % 10));

		marker++;
	}

	c.zero_justify();

	return c;
}

// �˷�������һ��һ����ķ����ȵ����ķ����ӷ������ұ�д���벻��临����ࡣÿ�β������ѵ�һ��
// ��������һ����λ��Ȼ������ƺ��������x�Ļ��ӵ����ս���У�����x�ǵڶ���������Ӧ�����֡���
// ���÷����ӷ���ʵ����һ���������������ɣ������ڶ��ڵڶ���������ÿ�����֣��ڲ�ѭ�����ִ�� 9
// �Σ�ʵ���ϲ�û���˷�̫���ʱ�䣬����һ����λ�ȼ����������Խ�λ�ƵĻ�������ʮ��������ǳ��� 10��
integer operator*(integer a, integer b)
{
	integer c = integer(0), row = a;
	row.signbit = PLUS;

	for (int i = 0; i < b.digits.size(); i++)
	{
		for (int j = 0; j < b.digits[i]; j++)
			c = (c + row);

		row = row << 1;
	}

	c.signbit = a.signbit * b.signbit;
	c.zero_justify();

	return c;
}

// �������㡣���������̲������ƣ��������ϱ���������һ�����֣�Ȼ���Լ�ȥ������
integer operator/(integer a, integer b)
{
	integer c, row;
	row.signbit = PLUS;

	// �̵ķ���Ϊ a �ķ��ų��� b �ķ��š�
	c.signbit = a.signbit * b.signbit;

	int v;
	// ����a�����λ��ʼ����
	for (int i = a.digits.size() - 1; i >= 0; i--)
	{
		row = row << 1;
		row.digits[0] = a.digits[i];

		// ������С�ڱ���������ȥ��������Ӧλ������ 1��
		v = 0;
		while (b <= row)
		{
			v++;
			row = row - b;
		}

		// �������� 1 λ���յõ����̼�Ϊ���λ��
		c = c << 1;
		c.digits[0] = (char)(v);
	}

	c.zero_justify();

	return c;
}

// �ݼ��㡣�ݾ��Ƿ������˷������ã�a^n = a^(n / 2) * a^(n / 2) * a^(n mod 2)�����Լ��ٳ�
// �Ĵ�����
integer operator^(integer a, int b)
{
	if (b == 0)
		return integer(1);

	if (b == 1)
		return a;

	if (b == 2)
		return a * a;

	return ((a ^ (b / 2)) ^ 2) * (a ^ (b % 2));
}

int main(int ac, char *av[])
{
	int cases;
	integer a;

	cin >> cases;
	while (cases--)
	{
		cin >> a;

		cout << ((a ^ 4) - integer(6) * (a ^ 3) +
			integer(23) * (a ^ 2) - integer(18) * a +
			integer(24)) / integer(24) << endl;
	}

	return 0;
}

