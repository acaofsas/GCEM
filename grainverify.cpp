#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include<math.h>

typedef unsigned _int32 u32;
typedef unsigned _int8 u8;

void Readtxt(u32 alpha[5], u32 beta[4], u32 c[259][8], u32 d[259][4], u32 g[259], u32 h[259], u32 H[259])
{
	FILE *filename = fopen("grain.txt", "r+");

	struct stat file;
	stat("grain.txt", &file);
	int lenth = file.st_size;
	char *fp = (char*)malloc(lenth);

	size_t sz = fread(fp, 1, (lenth), filename);

	int i, j, k, l, m;

	for (i = 0; i < 4; i++)
	{
		alpha[i] = 0;
		beta[i] = 0;
	}
	alpha[4] = 0;
	for (i = 0; i < 259; i++)
	{
		g[i] = 0;
		h[i] = 0;
		H[i] = 0;
		for (j = 0; j < 8; j++)c[i][j] = 0;
		for (j = 0; j < 4; j++)d[i][j] = 0;
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
				alpha[k / 32] ^= (fp[i + 9 + j] - '0') << (k % 32);
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
				beta[k / 32] ^= (fp[i + 8 + j] - '0') << (k % 32);
			}
			break;
		case'g':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				g[k] = fp[i + 2 + j] - '0';
			}
			break;
		case'h':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				h[k] = fp[i + 2 + j] - '0';
			}
			break;
		case'H':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				H[k] = fp[i + 2 + j] - '0';
			}
			break;
		case'c':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0; l = 0; m = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				while ((fp[i + 3 + j + l] >= '0') && (fp[i + 3 + j + l] <= '9'))
				{
					m = m * 10 + (fp[i + 3 + j + l] - '0');
					l++;
				}
				c[k][m / 32] ^= (fp[i + 6 + j + l] - '0') << (m % 32);
			}
			break;
		case'd':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0; l = 0; m = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				while ((fp[i + 3 + j + l] >= '0') && (fp[i + 3 + j + l] <= '9'))
				{
					m = m * 10 + (fp[i + 3 + j + l] - '0');
					l++;
				}
				d[k][m / 32] ^= (fp[i + 6 + j + l] - '0') << (m % 32);
			}
			break;
		default:break;
		}
	}
}

void gfunction(u8 g[16384])
{
	int i, j;
	u8 x[14];
	for (i = 0; i < 16384; i++)
	{
		for (j = 0; j < 14; j++)x[j] = (i >> j) & 1;
		g[i] = (x[0] & x[1]) ^ (x[2] & x[3]) ^ (x[4] & x[5]) ^ (x[6] & x[7]) ^ (x[8] & x[9]) ^ (x[10] & x[11]) ^ (x[12] & x[13]);
	}
}

void hfunction(u8 h[512])
{
	int i, j;
	u8 x[9];
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j < 9; j++)x[j] = (i >> j) & 1;
		h[i] = (x[0] & x[1]) ^ (x[2] & x[3]) ^ (x[4] & x[5]) ^ (x[6] & x[7]) ^ (x[0] & x[4] & x[8]);
	}
}

void puG(unsigned __int8 g[16384], int pug[16384]) 
{
	int x, a, i;
	int wt[16384];

	for (x = 0; x<16384; x++) 
	{
		wt[x] = 0;
		for (i = 0; i<14; i++) wt[x] ^= (x >> i) & 1;
		if (wt[x])	wt[x] = -1;
		else wt[x] = 1;
	}

	for (a = 0; a<16384; a++) 
	{
		pug[a] = 0;
		for (x = 0; x < 16384; x++)pug[a] += wt[g[x]] * wt[a&x]; //wt[g[x] ^ (a & x)];
	}
}

void puH(unsigned __int8 h[512], int puh[512]) 
{
	int x, a, i;
	int wt[512];

	for (x = 0; x<512; x++) 
	{
		wt[x] = 0;
		for (i = 0; i<9; i++) wt[x] ^= (x >> i) & 1;
		if (wt[x])	wt[x] = -1;
		else wt[x] = 1;
	}

	for (a = 0; a<512; a++)
	{
		puh[a] = 0;
		for (x = 0; x < 512; x++)puh[a] += wt[h[x] ^ (a & x)];
	}
}

void lfsr127(u32 x[128], u32 y[256])
{
	int i;

	for (i = 0; i < 128; i++)y[i] = x[i];
	for (i = 0; i < 128; i++)y[i + 128] = y[i] ^ y[i + 7] ^ y[i + 38] ^ y[i + 70] ^ y[i + 81] ^ y[i + 96];
}

void LFSR127(u32 beta[4], u32 c[8])
{
	u32 Beta[128];
	u32 C[256];
	u32 x[128];
	u32 y[256];
	u32 temp;
	int i, j;

	for (i = 0; i < 128; i++)Beta[i] = (beta[i / 32] >> (i % 32)) & 1;
	for (i = 0; i < 256; i++)C[i] = (c[i / 32] >> (i % 32)) & 1;

	for (i = 0; i < 128; i++)
	{
		for (j = 0; j < 128; j++)x[j] = 0;
		x[i] = 1;
		lfsr127(x, y);
		temp = 0;
		for (j = 0; j < 128; j++)temp ^= Beta[j] & x[j];
		for (j = 0; j < 256; j++)temp ^= C[j] & y[j];
		if (temp)
		{
			printf("fail\n");
			return;
		}
	}
	printf("pass\n");
}

u32 gverify(FILE *fp, int n, u32 cb[8], u32 ca[8], u32 db[4], u32 da[4], int pu[16834], int sign[2])
{

	int g1[14] = { 3,67,11,13,17,18,27,59,40,48,61,65,68,84 };
	int g2[19] = { 0,26,56,91,96,3,67,11,13,17,18,27,59,40,48,61,65,68,84 };
	int g3[5] = { 0,26,56,91,96 };
	int t;
	int i, j;
	u32 temp = 0;
	u32 input = 0;

	t = (n - 3) / 2;

	for (i = 0; i < 14; i++) 
	{
		temp |= ((db[g1[i] / 32] >> (g1[i] % 32)) ^ (da[(g1[i] - 1) / 32] >> ((g1[i] - 1) % 32))) & 1;
	}
	if (temp != ((da[3] >> 31) & 1))
	{
		return 9527;
	}

	for (i = 1; i < 5; i++) 
	{
		if ((((db[g3[i] / 32] >> (g3[i] % 32)) & 1) ^ ((da[(g3[i] - 1) / 32] >> ((g3[i] - 1) % 32)) & 1)) != ((da[3] >> 31) & 1))
		{
			return 9527;
		}
	}
	if ((db[0] & 1) != ((da[3] >> 31) & 1))
	{
		return 9527;
	}

	if ((((cb[t / 32] ^ ca[t / 32]) >> (t % 32)) & 1) != ((da[3] >> 31) & 1))
	{
		return 9527;
	}

	for (i = 1; i < 128; i++)
	{
		temp = 1;
		for (j = 0; j < 19; j++)
		{
			if (i == g2[j])temp &= 0;
		}
		if (temp)
		{		
			if (((db[i / 32] >> (i % 32)) & 1) == ((da[(i - 1) / 32] >> ((i - 1) % 32)) & 1))continue;
			else
			{
				return 9527;
			}
		}
	}
	for (i = 1; i < 256; i++)
	{
		if (i == t)continue;
		else if (((ca[i / 32] >> (i % 32)) & 1) != ((cb[i / 32] >> (i % 32)) & 1))
		{
			return 9527;
		}
	}

	for (i = 0; i < 14; i++)
	{
		input ^= ((da[g1[i] / 32] >> (g1[i] % 32)) & 1) << i;
	}
	if (pu[input] < 0)sign[0] ^= 1;

	return (7 * ((da[3] >> 31) & 1));
}

u32 hverify(FILE *fp, int n, u32 alpha[5], u32 cb[8], u32 ca[8], u32 db[4], u32 da[4], int pu[512], int sign[2])
{
	u32 p2[7] = { 2,15,36,45,64,73,89 };
	u32 pc[8] = { 8,13,20,42,60,79,95,93 };
	u32 pd[9] = { 2,15,36,45,64,73,89,12,95 };
	u32 temp;
	u32 input = 0;
	int i, j, t;

	t = (n - 2) / 2;

	for (i = 0; i < 7; i++) 
	{
		if ((((db[p2[i] / 32] ^ da[p2[i] / 32]) >> (p2[i] % 32)) & 1) != ((alpha[t / 32] >> (t % 32)) & 1))
		{
			printf("h%dfail,d_%d!=alpha_%d\n", n, p2[i], t);
			printf("d_%d = %d, alpha_%d = %d\n", p2[i], (((db[p2[i] / 32] ^ da[p2[i] / 32]) >> (p2[i] % 32)) & 1), t, ((alpha[t / 32] >> (t % 32)) & 1));
		}
	}
	if ((((cb[(t + 93) / 32] ^ ca[(t + 93) / 32]) >> ((t + 93) % 32)) & 1) != ((alpha[t / 32] >> (t % 32)) & 1))printf("h%dfail,c_%d!=alpha_%d\n", n, t, t);

	for (i = 0; i < 256; i++) 
	{
		temp = 1;
		for (j = 0; j < 8; j++)
		{
			if (i == (pc[j] + t))temp &= 0;
		}
		if (temp)
		{
			if ((((ca[i / 32] ^ cb[i / 32]) >> (i % 32)) & 1) != 0)
			{
				return 9527;
			}
		}
	}
	for (i = 0; i < 128; i++)
	{
		temp = 1;
		for (j = 0; j < 9; j++)
		{
			if (i == pd[j])temp &= 0;
		}
		if (temp)
		{
			if ((((da[i / 32] ^ db[i / 32]) >> (i % 32)) & 1) != 0)
			{
				return 9527;
			}
		}
	}

	input ^= ((da[0] ^ db[0]) >> 12) & 1;                                                //b_t+12
	input ^= (((ca[(t + 8) / 32] ^ cb[(t + 8) / 32]) >> ((t + 8) % 32)) & 1) << 1;       //s_t+8
	input ^= (((ca[(t + 13) / 32] ^ cb[(t + 13) / 32]) >> ((t + 13) % 32)) & 1) << 2;    //s_t+8
	input ^= (((ca[(t + 20) / 32] ^ cb[(t + 20) / 32]) >> ((t + 20) % 32)) & 1) << 3;    //s_t+20
	input ^= (((da[2] ^ db[2]) >> 31) & 1) << 4;                                         //b_t+95
	input ^= (((ca[(t + 42) / 32] ^ cb[(t + 42) / 32]) >> ((t + 42) % 32)) & 1) << 5;    //s_t+42
	input ^= (((ca[(t + 60) / 32] ^ cb[(t + 60) / 32]) >> ((t + 60) % 32)) & 1) << 6;    //s_t+60
	input ^= (((ca[(t + 79) / 32] ^ cb[(t + 79) / 32]) >> ((t + 79) % 32)) & 1) << 7;    //s_t+79
	input ^= (((ca[(t + 95) / 32] ^ cb[(t + 95) / 32]) >> ((t + 95) % 32)) & 1) << 8;    //s_t+95

	temp = input | (input >> 3) | (input >> 6);
	temp = (temp | (temp >> 1) | (temp >> 2)) & 1;
	if (temp == ((alpha[t / 32] >> (t % 32)) & 1))
	{
	}
	else
	{
		return 9527;
	}
	if (temp)
	{
		printf("%d, ", pu[input]);
		fprintf(fp, "%d, ", pu[input]);
	}
	else
	{
		printf("0, ");
		fprintf(fp, "0, ");
	}

	if (pu[input] < 0)sign[0] ^= 1;

	printf("cor%d\n", 4 * ((alpha[t / 32] >> (t % 32)) & 1));
	fprintf(fp, "cor%d\n", 4 * ((alpha[t / 32] >> (t % 32)) & 1));

	return (4 * ((alpha[t / 32] >> (t % 32)) & 1));
}

void doing()
{
	u32 alpha[5];
	u32 beta[4];
	u32 g[259];
	u32 h[259];
	u32 H[259];
	u32 c[259][8];
	u32 d[259][4];
	int i, j;
	u8 hvalue[512];
	u8 gvalue[16834];
	int puh[512];
	int pug[16384];
	int sign[2] = { 0 };
	u32 total = 0;
	FILE *fp = fopen("results.txt", "w");

	Readtxt(alpha, beta, c, d, g, h, H);
	hfunction(hvalue);
	puH(hvalue, puh);
	gfunction(gvalue);
	puG(gvalue, pug);

	LFSR127(beta, c[1]);
	for (i = 1; i < 130; i++)
	{
		j = 2 * i;
		total += hverify(fp, j, alpha, c[j - 1], c[j], d[j - 1], d[j], puh, sign);
		printf("total = %d\n", total);
	}
	for (i = 1; i < 129; i++)
	{
		j = 2 * i + 1;
		total += gverify(fp, j, c[j - 1], c[j], d[j - 1], d[j], pug, sign);
		printf("total = %d\n", total);
	}

	printf("alpha: %01x, %08x, %08x, %08x, %08x\n", alpha[4], alpha[3], alpha[2], alpha[1], alpha[0]);
	printf("beta: %08x, %08x, %08x, %08x\n", beta[3], beta[2], beta[1], beta[0]);
	fprintf(fp, "alpha: %01x, %08x, %08x, %08x, %08x\n", alpha[4], alpha[3], alpha[2], alpha[1], alpha[0]);
	fprintf(fp, "beta: %08x, %08x, %08x, %08x\n", beta[3], beta[2], beta[1], beta[0]);
	for (i = 1; i < 259; i++)
	{
		printf("d%d:  %08x, %08x, %08x, %08x, c%d:  %08x, %08x, %08x, %08x, %08x, %08x, %08x, %08x\n", i, d[i][3], d[i][2], d[i][1], d[i][0], i, c[i][7], c[i][6], c[i][5], c[i][4], c[i][3], c[i][2], c[i][1], c[i][0]);
		fprintf(fp, "d%d:  %08x, %08x, %08x, %08x, c%d:  %08x, %08x, %08x, %08x, %08x, %08x, %08x, %08x\n", i, d[i][3], d[i][2], d[i][1], d[i][0], i, c[i][7], c[i][6], c[i][5], c[i][4], c[i][3], c[i][2], c[i][1], c[i][0]);
	}

	printf("correlation%d£¬sign%d\n", total, sign[0]);
	fprintf(fp, "correlation%d£¬sign%d\n", total, sign[0]);
	fclose(fp);

	FILE *fp1 = fopen("trails.txt", "w");

	fprintf(fp1, "u32 Td[258][4];\n");
	fprintf(fp1, "u32 Tc[258][8];\n");
	for (i = 1; i < 258; i++)
	{
		for (j = 0; j < 4; j++)fprintf(fp1, "Td[%d][%d]=0x%08x;\n", i, j, d[i][j]);
		for (j = 0; j < 8; j++)fprintf(fp1, "Tc[%d][%d]=0x%08x;\n", i, j, c[i][j]);
		
	}

	c[1][105 / 32] ^= 1 << (105 % 32);
	c[1][207 / 32] ^= 1 << (207 % 32);

	printf("c[1]:  %08x, %08x, %08x, %08x, %08x, %08x, %08x, %08x\n", c[1][0], c[1][1], c[1][2], c[1][3], c[1][4], c[1][5], c[1][6], c[1][7]);
	fprintf(fp, "c[1]:  %08x, %08x, %08x, %08x, %08x, %08x, %08x, %08x\n", c[1][0], c[1][1], c[1][2], c[1][3], c[1][4], c[1][5], c[1][6], c[1][7]);

	fclose(fp1);
}

void main()
{
	doing();
}