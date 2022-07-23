#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include<math.h>

typedef unsigned _int32 u32;
typedef unsigned _int8 u8;

void Readtxt(u8 alpha[4], u8 beta[4], u8 gamma[4], u8 a[4], u8 b[4], u8 c[4], u8 d[4], u8 l[4], u8 m[4], u8 n[4], u8 v[4], u8 w[4], u8 p[4], u8 q[4], u8 x[4], u8 y[4], u8 z[4], u8 t[4])
{
	FILE *filename = fopen("snow2.txt", "r+");

	struct stat file;
	stat("snow2.txt", &file);
	int lenth = file.st_size;
	char *fp = (char*)malloc(lenth);

	size_t sz = fread(fp, 1, (lenth), filename);

	int i, j, k;

	for (i = 0; i < 4; i++)
	{
		alpha[i] = 0;
		beta[i] = 0;
		gamma[i] = 0;
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
		d[i] = 0;
		l[i] = 0;
		m[i] = 0;
		n[i] = 0;
		v[i] = 0;
		w[i] = 0;
		p[i] = 0;
		q[i] = 0;
		x[i] = 0;
		y[i] = 0;
		z[i] = 0;
		t[i] = 0;
	}
	for (i = 0; i < (lenth + 1); i++)
	{
		switch (fp[i])
		{
		case'a':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == 'l') && (fp[i + 2] == 'p') && (fp[i + 3] == 'h') && (fp[i + 4] == 'a') && (fp[i + 5] == '_'))
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
		case'g':
			if ((fp[i + 1] == 'a') && (fp[i + 2] == 'm') && (fp[i + 3] == 'm') && (fp[i + 4] == 'a') && (fp[i + 5] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 6 + j] >= '0') && (fp[i + 6 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 6 + j] - '0');
					j++;
				}
				gamma[k / 8] ^= (fp[i + 9 + j] - '0') << (k % 8);
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
		case'p':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				p[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		case'q':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				q[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
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
		case't':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				t[k / 8] ^= (fp[i + 5 + j] - '0') << (k % 8);
			}
			break;
		default:break;
		}
	}
}

int wt(u8 in)
{
	u8 temp;
	double w = 0;

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

int Parity(u8 state[4])
{
	int i;
	u8 temp = 0;
	for (i = 0; i < 4; i++)
	{
		temp ^= state[i];
	}
	temp = ((temp >> 4) ^ temp) & 0xf;
	temp = ((temp >> 2) ^ temp) & 0x3;
	temp = ((temp >> 1) ^ temp) & 1;
	return temp;
}

void l1(u8 a[4])
{
	u8 s[4];
#define ercheng1(x) ((x << 1) ^ (x >> 7 ? 0x1b : 0))
	s[0] = (ercheng1(a[0])) ^ (ercheng1(a[1])) ^ a[1] ^ a[2] ^ a[3];
	s[1] = a[0] ^ (ercheng1(a[1])) ^ (ercheng1(a[2])) ^ a[2] ^ a[3];
	s[2] = a[0] ^ a[1] ^ (ercheng1(a[2])) ^ (ercheng1(a[3])) ^ a[3];
	s[3] = (ercheng1(a[0])) ^ a[0] ^ a[1] ^ a[2] ^ (ercheng1(a[3]));
	for (int k = 0; k < 4; k++) a[k] = s[k];
}

void l2(u8 a[4])
{
	u8 s[4];
#define ercheng2(x) ((x << 1) ^ (x >> 7 ? 0x69 : 0))
	s[0] = (ercheng2(a[0])) ^ (ercheng2(a[1])) ^ a[1] ^ a[2] ^ a[3];
	s[1] = a[0] ^ (ercheng2(a[1])) ^ (ercheng2(a[2])) ^ a[2] ^ a[3];
	s[2] = a[0] ^ a[1] ^ (ercheng2(a[2])) ^ (ercheng2(a[3])) ^ a[3];
	s[3] = (ercheng2(a[0])) ^ a[0] ^ a[1] ^ a[2] ^ (ercheng2(a[3]));
	for (int k = 0; k < 4; k++) a[k] = s[k];
}

void L1(u8 in[4], u8 out[4], char Ch[])
{
	int i, j;
	u8 e[4];
	u8 temp[4];

	for (i = 0; i < 32; i++)
	{
		e[i / 8] = 1 << (i % 8);
		e[((i / 8) + 1) & 3] = 0;
		e[((i / 8) + 2) & 3] = 0;
		e[((i / 8) + 3) & 3] = 0;
		l1(e);
		for (j = 0; j < 4; j++)
		{
			temp[j] = out[j] & e[j];
		}
		if (Parity(temp) ^ ((in[i / 8] >> (i % 8)) & 1))
		{
			return;
		}
		else
		{
			continue;
		}
	}
}

void L2(u8 in[4], u8 out[4], char Ch[])
{
	int i, j;
	u8 e[4];
	u8 temp[4];

	for (i = 0; i < 32; i++)
	{
		e[i / 8] = 1 << (i % 8);
		e[((i / 8) + 1) & 3] = 0;
		e[((i / 8) + 2) & 3] = 0;
		e[((i / 8) + 3) & 3] = 0;
		l2(e);
		for (j = 0; j < 4; j++)
		{
			temp[j] = out[j] & e[j];
		}
		if (Parity(temp) ^ ((in[i / 8] >> (i % 8)) & 1))
		{
			return;
		}
		else
		{
			continue;
		}
	}
}

void pu(u8 S[256], int pu[256][256])   // 返回值是最大的非平凡线性逼近的Walsh谱绝对值 
{
	int x, a, b, i, max;
	int wt[256];

	for (x = 0; x<256; x++) // 计算每个字节中1的个数的奇偶性:(-1)的wt[x]次方 
	{
		wt[x] = 0;
		for (i = 0; i<8; i++) wt[x] ^= (x >> i) & 1;
		if (wt[x])	wt[x] = -1;
		else wt[x] = 1;
	}

	for (a = 0; a<256; a++)  // 输入mask 
	{
		for (b = 0; b<256; b++)	// 输出mask
		{
			pu[a][b] = 0;
			for (x = 0; x<256; x++)
				pu[a][b] += wt[(b&S[x]) ^ (a&x)];
		}
	}
	max = 0;
	for (a = 1; a<256; a++)  // 输入mask 
	{
		for (b = 1; b<256; b++)	// 输出mask
		{
			if (pu[a][b]>max) max = pu[a][b];
			else if (-pu[a][b]>max) max = -pu[a][b];
		}
	}
}

double S(u8 in[4], u8 out[4], int pu[256][256], char Ch[], int sym[2])
{
	int i;
	int temp[4];
	double cor = 0;
	for (i = 0; i < 4; i++)
	{
		temp[i] = pu[in[i]][out[i]];
		if (temp[i] < 0) sym[0] ^= 1;
		if (temp[i] != 0)
		{
			cor += log2((double)(256 / fabs(temp[i])));
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

void doing()
{
	u8 alpha[4];
	u8 beta[4];
	u8 gamma[4];
	u8 a[4];
	u8 b[4];
	u8 c[4];
	u8 d[4];
	u8 l[4];
	u8 m[4];
	u8 n[4];
	u8 v[4];
	u8 w[4];
	u8 p[4];
	u8 q[4];
	u8 x[4];
	u8 y[4];
	u8 z[4];
	u8 t[4];
	u8 g[4];

	u8 SR[256] = {	// AES的S盒
		0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
		0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
		0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
		0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
		0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
		0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
		0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
		0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
		0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
		0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
		0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
		0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
		0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
		0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
		0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
		0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16
	};
	u8 SQ[256] = {	// SNOW3G的S盒Q
		0x25, 0x24, 0x73, 0x67, 0xd7, 0xae, 0x5c, 0x30, 0xa4, 0xee, 0x6e, 0xcb, 0x7d, 0xb5, 0x82, 0xdb,
		0xe4, 0x8e, 0x48, 0x49, 0x4f, 0x5d, 0x6a, 0x78, 0x70, 0x88, 0xe8, 0x5f, 0x5e, 0x84, 0x65, 0xe2,
		0xd8, 0xe9, 0xcc, 0xed, 0x40, 0x2f, 0x11, 0x28, 0x57, 0xd2, 0xac, 0xe3, 0x4a, 0x15, 0x1b, 0xb9,
		0xb2, 0x80, 0x85, 0xa6, 0x2e, 0x02, 0x47, 0x29, 0x07, 0x4b, 0x0e, 0xc1, 0x51, 0xaa, 0x89, 0xd4,
		0xca, 0x01, 0x46, 0xb3, 0xef, 0xdd, 0x44, 0x7b, 0xc2, 0x7f, 0xbe, 0xc3, 0x9f, 0x20, 0x4c, 0x64,
		0x83, 0xa2, 0x68, 0x42, 0x13, 0xb4, 0x41, 0xcd, 0xba, 0xc6, 0xbb, 0x6d, 0x4d, 0x71, 0x21, 0xf4,
		0x8d, 0xb0, 0xe5, 0x93, 0xfe, 0x8f, 0xe6, 0xcf, 0x43, 0x45, 0x31, 0x22, 0x37, 0x36, 0x96, 0xfa,
		0xbc, 0x0f, 0x08, 0x52, 0x1d, 0x55, 0x1a, 0xc5, 0x4e, 0x23, 0x69, 0x7a, 0x92, 0xff, 0x5b, 0x5a,
		0xeb, 0x9a, 0x1c, 0xa9, 0xd1, 0x7e, 0x0d, 0xfc, 0x50, 0x8a, 0xb6, 0x62, 0xf5, 0x0a, 0xf8, 0xdc,
		0x03, 0x3c, 0x0c, 0x39, 0xf1, 0xb8, 0xf3, 0x3d, 0xf2, 0xd5, 0x97, 0x66, 0x81, 0x32, 0xa0, 0x00,
		0x06, 0xce, 0xf6, 0xea, 0xb7, 0x17, 0xf7, 0x8c, 0x79, 0xd6, 0xa7, 0xbf, 0x8b, 0x3f, 0x1f, 0x53,
		0x63, 0x75, 0x35, 0x2c, 0x60, 0xfd, 0x27, 0xd3, 0x94, 0xa5, 0x7c, 0xa1, 0x05, 0x58, 0x2d, 0xbd,
		0xd9, 0xc7, 0xaf, 0x6b, 0x54, 0x0b, 0xe0, 0x38, 0x04, 0xc8, 0x9d, 0xe7, 0x14, 0xb1, 0x87, 0x9c,
		0xdf, 0x6f, 0xf9, 0xda, 0x2a, 0xc4, 0x59, 0x16, 0x74, 0x91, 0xab, 0x26, 0x61, 0x76, 0x34, 0x2b,
		0xad, 0x99, 0xfb, 0x72, 0xec, 0x33, 0x12, 0xde, 0x98, 0x3b, 0xc0, 0x9b, 0x3e, 0x18, 0x10, 0x3a,
		0x56, 0xe1, 0x77, 0xc9, 0x1e, 0x9e, 0x95, 0xa3, 0x90, 0x19, 0xa8, 0x6c, 0x09, 0xd0, 0xf0, 0x86
	};
	int resultR[256][256];
	int resultQ[256][256];
	double tc = 0;
	int sym[2] = { 0,0 };
	int i;

	char Ach[] = "A";
	char Bch[] = "B";
	char Cch[] = "C";
	char xch[] = "x";
	char ych[] = "y";
	char zch[] = "z";
	char tch[] = "t";
	char pch[] = "p";
	char vch[] = "v";
	char wch[] = "w";

	pu(SR, resultR);
	pu(SQ, resultQ);

	Readtxt(alpha, beta, gamma, a, b, c, d, l, m, n, v, w, p, q, x, y, z, t);

	printf("alpha: %x %x %x %x\n", alpha[3], alpha[2], alpha[1], alpha[0]);
	printf("beta: %x %x %x %x\n", beta[3], beta[2], beta[1], beta[0]);
	printf("gamma: %x %x %x %x\n", gamma[3], gamma[2], gamma[1], gamma[0]);
	printf("a: %x %x %x %x\n", a[3], a[2], a[1], a[0]);
	printf("b: %x %x %x %x\n", b[3], b[2], b[1], b[0]);
	printf("c: %x %x %x %x\n", c[3], c[2], c[1], c[0]);
	printf("d: %x %x %x %x\n", d[3], d[2], d[1], d[0]);
	printf("l: %x %x %x %x\n", l[3], l[2], l[1], l[0]);
	printf("m: %x %x %x %x\n", m[3], m[2], m[1], m[0]);
	printf("n: %x %x %x %x\n", n[3], n[2], n[1], n[0]);
	printf("v: %x %x %x %x\n", v[3], v[2], v[1], v[0]);
	printf("w: %x %x %x %x\n", w[3], w[2], w[1], w[0]);
	printf("p: %x %x %x %x\n", p[3], p[2], p[1], p[0]);
	printf("q: %x %x %x %x\n", q[3], q[2], q[1], q[0]);
	printf("x: %x %x %x %x\n", x[3], x[2], x[1], x[0]);
	printf("y: %x %x %x %x\n", y[3], y[2], y[1], y[0]);
	printf("z: %x %x %x %x\n", z[3], z[2], z[1], z[0]);
	printf("t: %x %x %x %x\n", t[3], t[2], t[1], t[0]);

	exchange(m, beta, g);
	L1(c, beta, pch);

	tc += Mojia(a, m, alpha, x, xch, sym);
	tc += Mojia(alpha, l, b, y, ych, sym);
	tc += Mojia(b, n, beta, z, zch, sym);
	tc += S(a, c, resultR, Ach, sym);

	printf("correlation:%f,sign:%d\n", tc, sym[0]);

}

void main()
{
	doing();
}