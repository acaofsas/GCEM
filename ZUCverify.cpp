#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include<math.h>
#include<time.h>

typedef unsigned _int32 u32;
typedef unsigned _int8 u8;

void Readtxt(u8 alpha[4], u8 beta[4], u8 a[4], u8 b[4], u8 c[4], u8 d[4], u8 l[4], u8 m[4], u8 n[4], u8 u[4], u8 v[4], u8 w[4], u8 x[4], u8 y[4], u8 z[4])
{
	FILE *filename = fopen("zuc.txt", "r+");

	struct stat file;
	stat("zuc.txt", &file);
	int lenth = file.st_size;
	char *fp = (char*)malloc(lenth);

	size_t sz = fread(fp, 1, (lenth), filename);

	int i, j, k;

	for (i = 0; i < 4; i++)
	{
		alpha[i] = 0;
		beta[i] = 0;
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
		d[i] = 0;
		l[i] = 0;
		m[i] = 0;
		n[i] = 0;
		u[i] = 0;
		v[i] = 0;
		w[i] = 0;
		x[i] = 0;
		y[i] = 0;
		z[i] = 0;
	}
	for (i = 0; i < (lenth + 1); i++)
	{
		switch (fp[i])
		{
		case'a':
			if ((fp[i-1]=='\'') && (fp[i + 1] == 'l') && (fp[i + 2] == 'p') && (fp[i + 3] == 'h') && (fp[i + 4] == 'a') && (fp[i + 5] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 6 + j] >= '0') && (fp[i + 6 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 6 + j] - '0');
					j++;
				}
				alpha[k / 8] ^= (fp[i + 9 + j] - '0') << (k % 8);
			}
			else
			{
				if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
				{
					j = 0; k = 0;
					while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
					{
						k = k * 10 + (fp[i + 2 + j] - '0');
						j++;
					}
					a[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
				}
			}
			break;
		case'b':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == 'e') && (fp[i + 2] == 't') && (fp[i + 3] == 'a') && (fp[i + 4] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 5 + j] >= '0') && (fp[i + 5 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 5 + j] - '0');
					j++;
				}
				beta[k / 8] ^= (fp[i + 8 + j] - '0') << (k % 8);
			}
			else
			{
				if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
				{
					j = 0; k = 0;
					while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
					{
						k = k * 10 + (fp[i + 2 + j] - '0');
						j++;
					}
					b[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
				}
			}
			break;
		case'c':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				c[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		case'd':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				d[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		case'l':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				l[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		case'm':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				m[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		case'n':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				n[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		case'u':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				u[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		case'v':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				v[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		case'w':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				w[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		case'x':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				x[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		case'y':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				y[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		case'z':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				z[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		default:break;
		}
	}
}

int wt(u8 in)
{
	u8 temp;
	int w = 0;

	temp = in;
	while (temp != 0)
	{
		temp &= temp - 1;
		w++;
	}
	return w;
}

double Mojia(u8 in1[4], u8 in2[4], u8 out[4], u8 mid[4], char Mid[], int sym[2])
{
	int i;
	u8 In1[4];
	u8 In2[4];
	int temp;
	int e = 0;
	double cor = 0;
	int symb = 0;

	for (i = 0; i < 4; i++)
	{
		In1[i] = in1[i] ^ out[i];
		In2[i] = in2[i] ^ out[i];
	}

	for (i = 0; i < 4; i++) sym[0] ^= wt(In1[i] & In2[i]) & 1;

	for (i = 31; i >= 0; i--)
	{
		temp = (((out[i / 8] >> (i % 8)) & 1) << 2) ^ (((In1[i / 8] >> (i % 8)) & 1) << 1) ^ ((In2[i / 8] >> (i % 8)) & 1);
		if (e)
		{
			cor++;
			switch (temp)
			{
			case 0:
			case 3:
			case 5:
			case 6:break;
			case 1:
			case 2:
			case 4:
			case 7:e = 0; break;
			}
		}
		else
		{
			switch (temp)
			{
			case 0:break;
			case 4:e = 1; break;
			case 1:
			case 2:
			case 3:
			case 5:
			case 6:
			case 7:return 0;
			}
		}
	}
	return cor;
}

double Mojia1(u8 in1[4], u8 in2[4], u8 out[4], int sym[2])
{
	int i;
	u8 In1[4];
	u8 In2[4];
	int temp;
	int e = 0;
	double cor = 0;
	int symb = 0;

	for (i = 0; i < 4; i++)
	{
		In1[i] = in1[i] ^ out[i];
		In2[i] = in2[i] ^ out[i];
	}

	for (i = 0; i < 4; i++) sym[0] ^= wt(In1[i] & In2[i]) & 1;

	for (i = 31; i >= 0; i--)
	{
		temp = (((out[i / 8] >> (i % 8)) & 1) << 2) ^ (((In1[i / 8] >> (i % 8)) & 1) << 1) ^ ((In2[i / 8] >> (i % 8)) & 1);
		if (e)
		{
			cor++;
			switch (temp)
			{
			case 0:
			case 3:
			case 5:
			case 6:break;
			case 1:
			case 2:
			case 4:
			case 7:e = 0; break;
			}
		}
		else
		{
			switch (temp)
			{
			case 0:break;
			case 4:e = 1; break;
			case 1:
			case 2:
			case 3:
			case 5:
			case 6:
			case 7: return 9527;
			}
		}
	}
	return cor;
}

int Parity(u32 x)
{
	u32 temp = 0;
	temp = x;
	temp = ((temp >> 16) ^ temp) & 0xffff;
	temp = ((temp >> 8) ^ temp) & 0xff;
	temp = ((temp >> 4) ^ temp) & 0xf;
	temp = ((temp >> 2) ^ temp) & 0x3;
	temp = ((temp >> 1) ^ temp) & 1;
	return temp;
}

void l2(u32 x[2])             //x[0]=T1, x[1]=T2
{
	u32 temp;
	temp = (x[0] << 16) ^ (x[1] >> 16);
	x[1] = (x[1] << 16) ^ (x[0] >> 16);
	x[0] = temp;
	x[0] = (x[0] << 24) ^ (x[0] >> 8) ^ (x[0] << 18) ^ (x[0] >> 14) ^ (x[0] << 10) ^ (x[0] >> 22) ^ (x[0] << 2) ^ (x[0] >> 30) ^ x[0];
	x[1] = (x[1] << 30) ^ (x[1] >> 2) ^ (x[1] << 22) ^ (x[1] >> 10) ^ (x[1] << 14) ^ (x[1] >> 18) ^ (x[1] << 8) ^ (x[1] >> 24) ^ x[1];
}

u32 l21(u32 x)
{
	return x ^ (x << 2) ^ (x >> 30) ^ (x << 10) ^ (x >> 22) ^ (x << 18) ^ (x >> 14) ^ (x << 24) ^ (x >> 8);
}

u32 l22(u32 x)
{
	return x ^ (x << 8) ^ (x >> 24) ^ (x << 14) ^ (x >> 18) ^ (x << 22) ^ (x >> 10) ^ (x << 30) ^ (x >> 2);
}

void L1(u8 in1[4], u8 in2[4], u8 out[4])
{
	int i;
	if ((in2[2] & 1) != 0)printf("L1fail\n");
	in2[2] ^= ((in1[1] >> 7) & 1);
	for (i = 0; i < 4; i++)
	{
		if (in2[i] != out[i])printf("L1fail\n");
	}
}

void L2(u8 in1[4], u8 in2[4], u8 out1[4], u8 out2[4])
{
	int i;
	u32 temp[2];
	u32 In[2] = { 0 };
	u32 Out[2] = { 0 };
	for (i = 3; i >=0; i--)
	{
		In[0] = In[0] << 8;
		In[1] = In[1] << 8;
		Out[0] = Out[0] << 8;
		Out[1] = Out[1] << 8;
		In[0] ^= in1[i];
		In[1] ^= in2[i];
		Out[0] ^= out1[i];
		Out[1] ^= out2[i];
	}

	for (i = 0; i < 64; i++)
	{
		temp[i / 32] = 1 << (i % 32);
		temp[1 ^ (i / 32)] = 0;
		l2(temp);
	}

}

double L21(u8 in1[4], u8 in2[4], u8 out1[4], u8 out2[4])
{
	int i;
	u32 temp[2];
	u32 In[2] = { 0 };
	u32 Out[2] = { 0 };
	for (i = 3; i >= 0; i--)
	{
		In[0] = In[0] << 8;
		In[1] = In[1] << 8;
		Out[0] = Out[0] << 8;
		Out[1] = Out[1] << 8;
		In[0] ^= in1[i];
		In[1] ^= in2[i];
		Out[0] ^= out1[i];
		Out[1] ^= out2[i];
	}

	for (i = 0; i < 64; i++)
	{
		temp[i / 32] = 1 << (i % 32);
		temp[1 ^ (i / 32)] = 0;
		l2(temp);
		if (Parity((Out[0] & temp[0]) ^ (Out[1] & temp[1]) ^ (In[i / 32] & (1 << (i % 32)))))return 9527;
	}
	return 0;
}

void pu(u8 S[256], int pu[256][256]) 
{
	int x, a, b, i, max;
	int wt[256];

	for (x = 0; x<256; x++) 
	{
		wt[x] = 0;
		for (i = 0; i<8; i++) wt[x] ^= (x >> i) & 1;
		if (wt[x])	wt[x] = -1;
		else wt[x] = 1;
	}

	for (a = 0; a<256; a++)
	{
		for (b = 0; b<256; b++)
		{
			pu[a][b] = 0;
			for (x = 0; x<256; x++)
				pu[a][b] += wt[(b&S[x]) ^ (a&x)];
		}
	}
	max = 0;
	for (a = 1; a<256; a++)
	{
		for (b = 1; b<256; b++)	
		{
			if (pu[a][b]>max) max = pu[a][b];
			else if (-pu[a][b]>max) max = -pu[a][b];
		}
	}
}

double S(u8 in[4], u8 out[4], int pu0[256][256], int pu1[256][256], char Ch[], int sym[2])
{
	int i;
	int temp[2];
	double cor = 0;
	for (i = 0; i < 2; i++)
	{
		temp[i] = pu1[in[2 * i]][out[2 * i]];
		if (temp[i] < 0) sym[0] ^= 1;
		if (temp[i] != 0)
		{
			cor += log2((double)(256 / fabs(temp[i])));
		}
	}
	for (i = 0; i < 2; i++)
	{
		temp[i] = pu1[in[2 * i + 1]][out[2 * i + 1]];
		if (temp[i] < 0) sym[0] ^= 1;
		if (temp[i] != 0)
		{
			cor += log2((double)(256 / fabs(temp[i])));
		}
	}
	return cor;
}

double S111(u8 in[4], u8 out[4], int pu0[256][256], int pu1[256][256], int sym[2])
{
	int i;
	int temp[2];
	double cor = 0;
	for (i = 0; i < 2; i++)
	{
		temp[i] = pu1[in[2 * i]][out[2 * i]];
		if (temp[i] < 0) sym[0] ^= 1;
		if (temp[i] != 0)
		{
			cor += log2((double)(256 / fabs(temp[i])));
		}
		else
		{
			return 9527;
		}
	}
	for (i = 0; i < 2; i++)
	{
		temp[i] = pu1[in[2 * i + 1]][out[2 * i + 1]];
		if (temp[i] < 0) sym[0] ^= 1;
		if (temp[i] != 0)
		{
			cor += log2((double)(256 / fabs(temp[i])));
		}
		else
		{
			return 9527;
		}
	}
	return cor;
}

void exchange(u8 in1[4], u8 in2[4], u8 out[4])
{
	int i;
	for (i = 0; i < 4; i++)
	{
		out[i] = in1[i] ^ in2[i];
	}
}

u32 VectorMul(u32 A[32][32], u32 a) 
{
	int b[32];
	int c[32];
	u32 i, j, k;

	for (i = 0; i < 32; i++)
	{
		b[i] = (a >> i) & 1;
		c[i] = 0;
	}
	for (i = 0; i < 32; i++)
	{
		for (j = 0; j < 32; j++)
		{
			c[i] ^= b[j] & A[i][j];
		}
	}
	k = 0;
	for (i = 0; i < 32; i++)
	{
		k ^= c[i] << i;
	}
	return k;
}

void transpose(u32 A[32][32])
{
	int i, j;
	u32 B[32][32];
	for (i = 0; i < 32; i++)for (j = 0; j < 32; j++)B[i][j] = A[j][i];
	for (i = 0; i < 32; i++)for (j = 0; j < 32; j++)A[i][j] = B[i][j];
}

void inverse(u32 A[32][32], u32 B[32][32])
{
	int i, j, k, temp;
	unsigned _int32 D[32][64];
	for (i = 0; i<32; i++) for (j = 0; j<32; j++)
	{
		D[i][j] = A[i][j];
		if (i != j) D[i][j + 32] = 0;
		else D[i][j + 32] = 1;
	}
	for (i = 0; i<32; i++)
	{
		if (D[i][i] == 0)
		{
			for (j = i + 1; j<32; j++)
			{
				if (D[j][i])
				{
					for (k = 0; k<64; k++)
					{
						temp = D[i][k]; D[i][k] = D[j][k]; D[j][k] = temp;
					}
					//		break;
					goto L2;
				}
			}
		}
	L2:for (j = 0; j<32; j++)
	{
		if (j == i) continue;
		if (D[j][i])
		{
			for (k = 0; k<64; k++) D[j][k] ^= D[i][k];
		}
	}
	}
	for (i = 0; i<32; i++) for (j = 0; j<32; j++) B[i][j] = D[i][32 + j];
}

void MatrixL12(u32 A[32][32], u32 B[32][32])
{
	int i, j;
	u32 e, temp;

	for (i = 0; i < 32; i++)
	{
		e = 1 << i;
		temp = l21(e);
		for (j = 0; j < 32; j++)A[j][i] = (temp >> j) & 1;
	}

	for (i = 0; i < 32; i++)
	{
		e = 1 << i;
		temp = l22(e);
		for (j = 0; j < 32; j++)B[j][i] = (temp >> j) & 1;
	}
}

void doing()
{
	u8 alpha[4];
	u8 beta[4];
	u8 a[4];
	u8 b[4];
	u8 c[4];
	u8 d[4];
	u8 l[4];
	u8 m[4];
	u8 n[4];
	u8 u[4];
	u8 v[4];
	u8 w[4];
	u8 x[4];
	u8 y[4];
	u8 z[4];
	u8 g[4];

	u8 S0[256] = {	
		0x3e, 0x72, 0x5b, 0x47, 0xca, 0xe0, 0x00, 0x33, 0x04, 0xd1, 0x54, 0x98, 0x09, 0xb9, 0x6d, 0xcb,
		0x7b, 0x1b, 0xf9, 0x32, 0xaf, 0x9d, 0x6a, 0xa5, 0xb8, 0x2d, 0xfc, 0x1d, 0x08, 0x53, 0x03, 0x90,
		0x4d, 0x4e, 0x84, 0x99, 0xe4, 0xce, 0xd9, 0x91, 0xdd, 0xb6, 0x85, 0x48, 0x8b, 0x29, 0x6e, 0xac,
		0xcd, 0xc1, 0xf8, 0x1e, 0x73, 0x43, 0x69, 0xc6, 0xb5, 0xbd, 0xfd, 0x39, 0x63, 0x20, 0xd4, 0x38,
		0x76, 0x7d, 0xb2, 0xa7, 0xcf, 0xed, 0x57, 0xc5, 0xf3, 0x2c, 0xbb, 0x14, 0x21, 0x06, 0x55, 0x9b,
		0xe3, 0xef, 0x5e, 0x31, 0x4f, 0x7f, 0x5a, 0xa4, 0x0d, 0x82, 0x51, 0x49, 0x5f, 0xba, 0x58, 0x1c,
		0x4a, 0x16, 0xd5, 0x17, 0xa8, 0x92, 0x24, 0x1f, 0x8c, 0xff, 0xd8, 0xae, 0x2e, 0x01, 0xd3, 0xad,
		0x3b, 0x4b, 0xda, 0x46, 0xeb, 0xc9, 0xde, 0x9a, 0x8f, 0x87, 0xd7, 0x3a, 0x80, 0x6f, 0x2f, 0xc8,
		0xb1, 0xb4, 0x37, 0xf7, 0x0a, 0x22, 0x13, 0x28, 0x7c, 0xcc, 0x3c, 0x89, 0xc7, 0xc3, 0x96, 0x56,
		0x07, 0xbf, 0x7e, 0xf0, 0x0b, 0x2b, 0x97, 0x52, 0x35, 0x41, 0x79, 0x61, 0xa6, 0x4c, 0x10, 0xfe,
		0xbc, 0x26, 0x95, 0x88, 0x8a, 0xb0, 0xa3, 0xfb, 0xc0, 0x18, 0x94, 0xf2, 0xe1, 0xe5, 0xe9, 0x5d,
		0xd0, 0xdc, 0x11, 0x66, 0x64, 0x5c, 0xec, 0x59, 0x42, 0x75, 0x12, 0xf5, 0x74, 0x9c, 0xaa, 0x23,
		0x0e, 0x86, 0xab, 0xbe, 0x2a, 0x02, 0xe7, 0x67, 0xe6, 0x44, 0xa2, 0x6c, 0xc2, 0x93, 0x9f, 0xf1,
		0xf6, 0xfa, 0x36, 0xd2, 0x50, 0x68, 0x9e, 0x62, 0x71, 0x15, 0x3d, 0xd6, 0x40, 0xc4, 0xe2, 0x0f,
		0x8e, 0x83, 0x77, 0x6b, 0x25, 0x05, 0x3f, 0x0c, 0x30, 0xea, 0x70, 0xb7, 0xa1, 0xe8, 0xa9, 0x65,
		0x8d, 0x27, 0x1a, 0xdb, 0x81, 0xb3, 0xa0, 0xf4, 0x45, 0x7a, 0x19, 0xdf, 0xee, 0x78, 0x34, 0x60
	};
	u8 S1[256] = {	
		0x55, 0xc2, 0x63, 0x71, 0x3b, 0xc8, 0x47, 0x86, 0x9f, 0x3c, 0xda, 0x5b, 0x29, 0xaa, 0xfd, 0x77,
		0x8c, 0xc5, 0x94, 0x0c, 0xa6, 0x1a, 0x13, 0x00, 0xe3, 0xa8, 0x16, 0x72, 0x40, 0xf9, 0xf8, 0x42,
		0x44, 0x26, 0x68, 0x96, 0x81, 0xd9, 0x45, 0x3e, 0x10, 0x76, 0xc6, 0xa7, 0x8b, 0x39, 0x43, 0xe1,
		0x3a, 0xb5, 0x56, 0x2a, 0xc0, 0x6d, 0xb3, 0x05, 0x22, 0x66, 0xbf, 0xdc, 0x0b, 0xfa, 0x62, 0x48,
		0xdd, 0x20, 0x11, 0x06, 0x36, 0xc9, 0xc1, 0xcf, 0xf6, 0x27, 0x52, 0xbb, 0x69, 0xf5, 0xd4, 0x87,
		0x7f, 0x84, 0x4c, 0xd2, 0x9c, 0x57, 0xa4, 0xbc, 0x4f, 0x9a, 0xdf, 0xfe, 0xd6, 0x8d, 0x7a, 0xeb,
		0x2b, 0x53, 0xd8, 0x5c, 0xa1, 0x14, 0x17, 0xfb, 0x23, 0xd5, 0x7d, 0x30, 0x67, 0x73, 0x08, 0x09,
		0xee, 0xb7, 0x70, 0x3f, 0x61, 0xb2, 0x19, 0x8e, 0x4e, 0xe5, 0x4b, 0x93, 0x8f, 0x5d, 0xdb, 0xa9,
		0xad, 0xf1, 0xae, 0x2e, 0xcb, 0x0d, 0xfc, 0xf4, 0x2d, 0x46, 0x6e, 0x1d, 0x97, 0xe8, 0xd1, 0xe9,
		0x4d, 0x37, 0xa5, 0x75, 0x5e, 0x83, 0x9e, 0xab, 0x82, 0x9d, 0xb9, 0x1c, 0xe0, 0xcd, 0x49, 0x89,
		0x01, 0xb6, 0xbd, 0x58, 0x24, 0xa2, 0x5f, 0x38, 0x78, 0x99, 0x15, 0x90, 0x50, 0xb8, 0x95, 0xe4,
		0xd0, 0x91, 0xc7, 0xce, 0xed, 0x0f, 0xb4, 0x6f, 0xa0, 0xcc, 0xf0, 0x02, 0x4a, 0x79, 0xc3, 0xde,
		0xa3, 0xef, 0xea, 0x51, 0xe6, 0x6b, 0x18, 0xec, 0x1b, 0x2c, 0x80, 0xf7, 0x74, 0xe7, 0xff, 0x21,
		0x5a, 0x6a, 0x54, 0x1e, 0x41, 0x31, 0x92, 0x35, 0xc4, 0x33, 0x07, 0x0a, 0xba, 0x7e, 0x0e, 0x34,
		0x88, 0xb1, 0x98, 0x7c, 0xf3, 0x3d, 0x60, 0x6c, 0x7b, 0xca, 0xd3, 0x1f, 0x32, 0x65, 0x04, 0x28,
		0x64, 0xbe, 0x85, 0x9b, 0x2f, 0x59, 0x8a, 0xd7, 0xb0, 0x25, 0xac, 0xaf, 0x12, 0x03, 0xe2, 0xf2
	};
	int result0[256][256];
	int result1[256][256];
	double tc = 0;
	int sym[2] = { 0,0 };

	char Ach[] = "A";
	char Bch[] = "B";
	char Cch[] = "C";
	char xch[] = "x";
	char ych[] = "y";
	char zch[] = "z";
	char tch[] = "t";
	char pch[] = "p";
	char uch[] = "u";
	char vch[] = "v";
	char wch[] = "w";

	pu(S0, result0);
	pu(S1, result1);

	Readtxt(alpha, beta, a, b, c, d, l, m, n, u, v, w, x, y, z);

	exchange(a, v, g);

	printf("alpha: %x %x %x %x\n", alpha[3], alpha[2], alpha[1], alpha[0]);
	printf("beta: %x %x %x %x\n", beta[3], beta[2], beta[1], beta[0]);
	printf("a: %x %x %x %x\n", a[3], a[2], a[1], a[0]);
	printf("b: %x %x %x %x\n", b[3], b[2], b[1], b[0]);
	printf("c: %x %x %x %x\n", c[3], c[2], c[1], c[0]);
	printf("d: %x %x %x %x\n", d[3], d[2], d[1], d[0]);
	printf("l: %x %x %x %x\n", l[3], l[2], l[1], l[0]);
	printf("m: %x %x %x %x\n", m[3], m[2], m[1], m[0]);
	printf("n: %x %x %x %x\n", n[3], n[2], n[1], n[0]);
	printf("u: %x %x %x %x\n", u[3], u[2], u[1], u[0]);
	printf("v: %x %x %x %x\n", v[3], v[2], v[1], v[0]);
	printf("w: %x %x %x %x\n", w[3], w[2], w[1], w[0]);
	printf("x: %x %x %x %x\n", x[3], x[2], x[1], x[0]);
	printf("y: %x %x %x %x\n", y[3], y[2], y[1], y[0]);
	printf("z: %x %x %x %x\n", z[3], z[2], z[1], z[0]);
	printf("g: %x %x %x %x\n", g[3], g[2], g[1], g[0]);


	L1(g, b, w);
	L2(u, d, l, m);

	tc += Mojia(v, c, u, x, xch, sym);
	tc += Mojia(v, d, alpha, y, ych, sym);
	tc += Mojia(w, n, beta, z, zch, sym);
	tc += S(l, w, result0, result1, Ach, sym);
	tc += S(m, n, result0, result1, Bch, sym);

	printf("correlation:%f,sign:%d\n", tc, sym[0]);

	u32 A[32][32];
	u32 AA[32][32];
	u32 B[32][32];
	u32 BB[32][32];
	unsigned int time1, time2;

	MatrixL12(A, B);
	transpose(A);
	transpose(B);
	inverse(A, AA);
	inverse(B, BB);

	int i, j, k, h;


	FILE *fp = fopen("traverse_un.txt", "w");
	double total = 0;
	double ntemp;
	double utemp;
	u32 tempu;
	u32 tempd;
	int sym1[2][2] = { 0 };

	u8 nt[0x400001][4] = { 0 };
	u8 ut[0x2000001][4] = { 0 };
	int nnum = 0;
	int unum = 0;

	time1 = time(NULL);
	h = 0;
	for (i = 1; i < 0x400001; i++)
	{
		for (j = 0; j < 4; j++)nt[h][j] = (i >> (8 * j)) & 0xff;
		if (Mojia1(w, nt[h], beta, sym1[0]) > 9000)continue;
		else h++;
	}
	for (j = 0; j < 4; j++)nt[h][j] = 0;
	nnum = h;
	h = 0;
	for (i = 1; i < 0x2000001; i++)
	{
		for (j = 0; j < 4; j++)ut[h][j] = (i >> (8 * j)) & 0xff;
		if (Mojia1(v, c, ut[h], sym1[0]) > 9000)continue;
		else h++;
	}
	for (j = 0; j < 4; j++)ut[h][j] = 0;
	unum = h;
	
	for (i = 0; i < nnum; i++)
	{
		sym1[0][0] = 0;
		ntemp = 0;
		ntemp += Mojia1(w, nt[i], beta, sym1[0]);
		if (ntemp > 9000)continue;
		for (j = 0; j < unum; j++)
		{
			utemp = ntemp;
			sym1[1][0] = sym1[0][0];
			tempu = (((u32)ut[j][1]) << 24) ^ (((u32)ut[j][0]) << 16) ^ (((u32)d[3]) << 8) ^ ((u32)d[2]);
			tempd = (((u32)d[1]) << 24) ^ (((u32)d[0]) << 16) ^ (((u32)ut[j][3]) << 8) ^ ((u32)ut[j][2]);

			tempu = VectorMul(AA, tempu);
			tempd = VectorMul(BB, tempd);
			for (k = 0; k < 4; k++)
			{
				l[k] = (tempu >> (k * 8)) & 0xff;
				m[k] = (tempd >> (k * 8)) & 0xff;
			}
			utemp += Mojia1(v, c, ut[j], sym1[1]);
			if (utemp > 9000)continue;
			utemp += S111(l, w, result0, result1, sym1[1]);
			if (utemp > 9000)continue;
			utemp += S111(m, nt[i], result0, result1, sym1[1]);
			if (utemp > 9000)continue;
			utemp += Mojia1(d, v, alpha, sym1[1]);
			if (utemp > 9000)continue;
			printf("delta5 = %02x%02x%02x%02x, delta3 = %02x%02x%02x%02x, correlation: %f, sign: %d\n", nt[i][3], nt[i][2], nt[i][1], nt[i][0], ut[j][3], ut[j][2], ut[j][1], ut[j][0], utemp, sym1[1][0]);
			fprintf(fp, "delta5 = %02x%02x%02x%02x, delta3 = %02x%02x%02x%02x, correlation: %f, sign: %d\n", nt[i][3], nt[i][2], nt[i][1], nt[i][0], ut[j][3], ut[j][2], ut[j][1], ut[j][0], utemp, sym1[1][0]);
			total += pow(2, (20 - utemp))*pow((-1), sym1[1][0]);
		}
	}
	
	for (i = 1; i < 0x400001; i++)
	{
		for (j = 0; j < 4; j++)nt[i][j] = 0;
	}
	for (i = 1; i < 0x2000001; i++)
	{
		for (j = 0; j < 4; j++)ut[i][j] = 0;
	}
	v[2] ^= 1;
	w[1] ^= 0x80;

	h = 0;
	for (i = 1; i < 0x400001; i++)
	{
		for (j = 0; j < 4; j++)nt[h][j] = (i >> (8 * j)) & 0xff;
		if (Mojia1(w, nt[h], beta, sym1[0]) > 9000)continue;
		else h++;
	}
	for (j = 0; j < 4; j++)nt[h][j] = 0;
	nnum = h;
	h = 0;
	for (i = 1; i < 0x2000001; i++)
	{
		for (j = 0; j < 4; j++)ut[h][j] = (i >> (8 * j)) & 0xff;
		if (Mojia1(v, c, ut[h], sym1[0]) > 9000)continue;
		else h++;
	}
	for (j = 0; j < 4; j++)ut[h][j] = 0;
	unum = h;
	
	for (i = 0; i < nnum; i++)
	{
		sym1[0][0] = 0;
		ntemp = 0;
		ntemp += Mojia1(w, nt[i], beta, sym1[0]);
		if (ntemp > 9000)continue;
		for (j = 0; j < unum; j++)
		{
			utemp = ntemp;
			sym1[1][0] = sym1[0][0];
			tempu = (((u32)ut[j][1]) << 24) ^ (((u32)ut[j][0]) << 16) ^ (((u32)d[3]) << 8) ^ ((u32)d[2]);
			tempd = (((u32)d[1]) << 24) ^ (((u32)d[0]) << 16) ^ (((u32)ut[j][3]) << 8) ^ ((u32)ut[j][2]);

			tempu = VectorMul(AA, tempu);
			tempd = VectorMul(BB, tempd);
			for (k = 0; k < 4; k++)
			{
				l[k] = (tempu >> (k * 8)) & 0xff;
				m[k] = (tempd >> (k * 8)) & 0xff;
			}
			utemp += Mojia1(v, c, ut[j], sym1[1]);
			if (utemp > 9000)continue;
			utemp += S111(l, w, result0, result1, sym1[1]);
			if (utemp > 9000)continue;
			utemp += S111(m, nt[i], result0, result1, sym1[1]);
			if (utemp > 9000)continue;
			utemp += Mojia1(d, v, alpha, sym1[1]);
			if (utemp > 9000)continue;
			printf("delta5 = %02x%02x%02x%02x, delta3 = %02x%02x%02x%02x, correlation: %f, sign: %d\n", nt[i][3], nt[i][2], nt[i][1], nt[i][0], ut[j][3], ut[j][2], ut[j][1], ut[j][0], utemp, sym1[1][0]);
			fprintf(fp, "delta5 = %02x%02x%02x%02x, delta3 = %02x%02x%02x%02x, correlation: %f, sign: %d\n", nt[i][3], nt[i][2], nt[i][1], nt[i][0], ut[j][3], ut[j][2], ut[j][1], ut[j][0], utemp, sym1[1][0]);
			total += pow(2, (20 - utemp))*pow((-1), sym1[1][0]);
		}
	}
	if (total > 0)sym[1] = 1;
	else
	{
		sym[1] = -1;
		total = (-1)*total;
	}
	total = log2(total) - 20;
	printf("alpha: 0x%02x%02x%02x%02x\n", alpha[3], alpha[2], alpha[1], alpha[0]);
	printf("beta: 0x%02x%02x%02x%02x\n", beta[3], beta[2], beta[1], beta[0]);
	printf("a1: 0x%02x%02x\n", v[1], v[0]);
	printf("a2: 0x%02x%02x\n", c[3], c[2]);
	printf("a3: 0x%02x%02x\n", c[1], c[0]);
	printf("a4: 0x%02x%02x\n", d[3], d[2]);
	printf("a5: 0x%02x%02x\n", d[1], d[0]);
	printf("a6: 0x%02x%02x\n", alpha[3], alpha[2]);
	printf("a7: 0x%02x%02x\n", alpha[1], alpha[0]);
	printf("a8: 0x%02x%02x\n", w[3], w[2]);
	printf("a9: 0x%02x%02x\n", beta[3], beta[2]);
	printf("a10: 0x%02x%02x\n", beta[1], beta[0]);
	printf("b(31bits): 0x%02x%02x%02x%02x\n", (v[3] >> 1), (((v[2] >> 1) ^ (v[3] << 7)) & 0xff), ((w[1] ^ (v[2] << 7)) & 0xff), w[0]);
	fprintf(fp, "alpha: 0x%02x%02x%02x%02x\n", alpha[3], alpha[2], alpha[1], alpha[0]);
	fprintf(fp, "beta: 0x%02x%02x%02x%02x\n", beta[3], beta[2], beta[1], beta[0]);
	fprintf(fp, "a1: 0x%02x%02x\n", v[1], v[0]);
	fprintf(fp, "a2: 0x%02x%02x\n", c[3], c[2]);
	fprintf(fp, "a3: 0x%02x%02x\n", c[1], c[0]);
	fprintf(fp, "a4: 0x%02x%02x\n", d[3], d[2]);
	fprintf(fp, "a5: 0x%02x%02x\n", d[1], d[0]);
	fprintf(fp, "a6: 0x%02x%02x\n", alpha[3], alpha[2]);
	fprintf(fp, "a7: 0x%02x%02x\n", alpha[1], alpha[0]);
	fprintf(fp, "a8: 0x%02x%02x\n", w[3], w[2]);
	fprintf(fp, "a9: 0x%02x%02x\n", beta[3], beta[2]);
	fprintf(fp, "a10: 0x%02x%02x\n", beta[1], beta[0]);
	fprintf(fp, "b(31bits): 0x%02x%02x%02x%02x\n", (v[3] >> 1), (((v[2] >> 1) ^ (v[3] << 7)) & 0xff), ((w[1] ^ (v[2] << 7)) & 0xff), w[0]);
	printf("total correlation: %f, ", total);
	fprintf(fp, "total correlation: %f, ", total);
	printf("sign: %d\n", sym[1]);
	fprintf(fp, "sign: %d\n", sym[1]);

	u8 xxxx[4] = { 0 };

	for (i = 0x20; i < 0x40; i++)
	{
		xxxx[2] = i;
		if (Mojia1(xxxx, b, beta, sym1[0]) < 9000)printf("%02x----%f\n", xxxx[2], Mojia1(xxxx, b, beta, sym1[0]));
	}



}

void main()
{
	doing();
}