/*
* Copyright (c) 2003,������̩�Ƶ��Ӽ����������ι�˾�з���
* All rights reserved.
* 
* Filename��g711.h
* �ļ���ʶ�������ù���ƻ���
* ժ    Ҫ��G.711 Coder and Decoder��u-law, A-law and linear PCM conversions.
* 
* ��ǰ�汾��1.1
* ��    �ߣ�DengBaokuan
* ������ڣ�April 08, 2003
* ȡ���汾��1.0 
* ԭ����  ��from H.323
* ������ڣ�December 30, 1994*/
static int ulaw2alaw ( int );
static int alaw2ulaw ( int);
int ulaw2linear( int );
int linear2ulaw( int );
int alaw2linear(int	);	
int linear2alaw(int	);

