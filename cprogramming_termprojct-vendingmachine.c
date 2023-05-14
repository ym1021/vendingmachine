#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define EIGHT 800
#define NINE 900
#define TEN 1000

int calculate(char key, int coin, int num);
int pricecheck(char key, int coin, int num);
int price(char key, int coin, int num);
int print(char key, int coin, int num);
int product(char key, int coin, int num);
int reset(char key, int coin, int num);

static int rev[] = {10, 10, 10, 10, 10, 10, 10, 10, 10};

// 시작 화면
int start(int coin)
{
  puts("**************************************");
  puts("**********Bremen 음료자판기***********");
  puts("**************************************");
  puts("--------------------------------------");
  puts("   ※ 시스템을 초기화했습니다. ※");
  puts("--------------------------------------");
  printf("- 1번 : 펩시 <800원>\n- 2번 : 환타 <800원>\n- 3번 : 사이다 <800원>\n");
  printf("- 4번 : 알로에 <900원>\n- 5번 : 탄산수 <900원>\n- 6번 : 비타500 <900원>\n");
  printf("- 7번 : 딸기주스 <1000원>\n- 8번 : 포도주스 <1000원>\n- 9번 : 오렌지주스 <1000원>\n");
  puts("--------------------------------------");
  printf("※ 현재 투입된 총 금액 : %d원입니다. ※\n", coin);
  puts("--------------------------------------");
  puts("    ★★ 메뉴 키<key> 안내 ★★");
  puts("--------------------------------------");
  printf("- b<B> : 동전 투입\n- q<Q> : 음료수 선택\n");
  printf("- w<W> : 자판기 판매 매출 보기\n- e<E> : 자판기 판매 매출 초기화\n");
  puts("--------------------------------------");
  printf("- a<A> : 10원짜리 동전 투입\n- s<S> : 50원짜리 동전 투입\n");
  printf("- d<D> : 100원짜리 동전 투입\n- f<F> : 500원짜리 동전 투입\n");
  puts("--------------------------------------");
  printf("- x<X> : 프로그램 종료\n");
  puts("--------------------------------------");
  puts("**************************************");
  return coin;
}

// 키 입력받기
int print(char key, int coin, int num)
{
  printf("→ key를 입력하세요 : ");
  scanf(" %c", &key);
  switch (key)
  {
  case 'b':
  case 'B':
    pricecheck(key, coin, num);
    break;
  case 'w':
  case 'W':
    product(key, coin, num);
    break;
  case 'e':
  case 'E':
    reset(key, coin, num);
    break;
  case 'x':
  case 'X':
    break;
  default:
    print(key, coin, num);
    break;
  }
  return key;
}

// 동전 투입
int pricecheck(char key, int coin, int num)
{
  while (key != 'Q' && key != 'q')
  {
    printf("→ key를 입력하세요 : ");
    scanf(" %c", &key);
    switch (key)
    {
    case 'a':
    case 'A':
      coin += 10;
      printf("※ 현재 투입된 총 금액 : %d원입니다. ※\n", coin);
      puts("--------------------------------------");
      break;
    case 's':
    case 'S':
      coin += 50;
      printf("※ 현재 투입된 총 금액 : %d원입니다. ※\n", coin);
      puts("--------------------------------------");
      break;
    case 'd':
    case 'D':
      coin += 100;
      printf("※ 현재 투입된 총 금액 : %d원입니다. ※\n", coin);
      puts("--------------------------------------");
      break;
    case 'f':
    case 'F':
      coin += 500;
      printf("※ 현재 투입된 총 금액 : %d원입니다. ※\n", coin);
      puts("--------------------------------------");
      break;
    default:
      return pricecheck(key, coin, num);
    }
  }
  key = 'z';
  return price(key, coin, num);
}

// 음료수 선택
int price(char key, int coin, int num)
{
  printf("→ 품목번호를 입력하세요 : ");
  scanf(" %d", &num);
  switch (num)
  {
  case 1:
    if (rev[0] == 0)
    {
      printf("펩시 재고가 없습니다.\n다시 선택하세요.\n");
      puts("--------------------------------------");
      return price(key, coin, num);
    }
    else
    {
      printf("펩시 800원입니다.\n");
      puts("--------------------------------------");
    }
    break;
  case 2:
    if (rev[1] == 0)
    {
      printf("환타 재고가 없습니다.\n다시 선택하세요.\n");
      puts("--------------------------------------");
      return price(key, coin, num);
    }
    else
    {
      printf("환타 800원입니다.\n");
      puts("--------------------------------------");
    }
    break;
  case 3:
    if (rev[2] == 0)
    {
      printf("사이다 재고가 없습니다.\n다시 선택하세요.\n");
      puts("--------------------------------------");
      return price(key, coin, num);
    }
    else
    {
      printf("사이다 800원입니다.\n");
      puts("--------------------------------------");
    }
    break;
  case 4:
    if (rev[3] == 0)
    {
      printf("알로에 재고가 없습니다.\n다시 선택하세요.\n");
      puts("--------------------------------------");
      return price(key, coin, num);
    }
    else
    {
      printf("알로에 900원입니다.\n");
      puts("--------------------------------------");
    }
    break;
  case 5:
    if (rev[4] == 0)
    {
      printf("탄산수 재고가 없습니다.\n다시 선택하세요.\n");
      puts("--------------------------------------");
      return price(key, coin, num);
    }
    else
    {
      printf("탄산수 900원입니다.\n");
      puts("--------------------------------------");
    }
    break;
  case 6:
    if (rev[5] == 0)
    {
      printf("비타500 재고가 없습니다.\n다시 선택하세요.\n");
      puts("--------------------------------------");
      return price(key, coin, num);
    }
    else
    {
      printf("비타500 900원입니다.\n");
      puts("--------------------------------------");
    }
    break;
  case 7:
    if (rev[6] == 0)
    {
      printf("딸기주스 재고가 없습니다.\n다시 선택하세요.\n");
      puts("--------------------------------------");
      return price(key, coin, num);
    }
    else
    {
      printf("딸기주스 1000원입니다.\n");
      puts("--------------------------------------");
    }
    break;
  case 8:
    if (rev[7] == 0)
    {
      printf("포도주스 재고가 없습니다.\n다시 선택하세요.\n");
      puts("--------------------------------------");
      return price(key, coin, num);
    }
    else
    {
      printf("포도주스 1000원입니다.\n");
      puts("--------------------------------------");
    }
    break;
  case 9:
    if (rev[8] == 0)
    {
      printf("오렌지주스 재고가 없습니다.\n다시 선택하세요.\n");
      puts("--------------------------------------");
      return price(key, coin, num);
    }
    else
    {
      printf("오렌지주스 1000원입니다.\n");
      puts("--------------------------------------");
    }
    break;
  default:
    printf("다시 선택하세요.\n");
    return price(key, coin, num);
  }
  return calculate(key, coin, num);
}

// 거스름돈 계산과 반환, 음료수 제공
int calculate(char key, int coin, int num)
{
  switch (num)
  {
  case 1:
    if (coin < EIGHT)
    {
      printf("돈이 부족합니다. 동전을 반환합니다.\n");
      puts("--------------------------------------");
      coin = 0;
      return print(key, coin, num);
    }
    else if (coin > EIGHT)
    {
      printf("잔돈 %d원을 반환하였습니다.\n음료를 꺼내주세요\n", coin - EIGHT);
      puts("--------------------------------------");
    }
    else
    {
      printf("음료를 꺼내주세요\n");
      puts("--------------------------------------");
    }
    rev[0] -= 1;
    break;
  case 2:
    if (coin < EIGHT)
    {
      printf("돈이 부족합니다. 동전을 반환합니다.\n");
      puts("--------------------------------------");
      coin = 0;
      return print(key, coin, num);
    }
    else if (coin > EIGHT)
    {
      printf("잔돈 %d원을 반환하였습니다.\n음료를 꺼내주세요\n", coin - EIGHT);
      puts("--------------------------------------");
    }
    else
    {
      printf("음료를 꺼내주세요\n");
      puts("--------------------------------------");
    }
    rev[1] -= 1;
    break;
  case 3:
    if (coin < EIGHT)
    {
      printf("돈이 부족합니다. 동전을 반환합니다.\n");
      puts("--------------------------------------");
      coin = 0;
      return print(key, coin, num);
    }
    else if (coin > EIGHT)
    {
      printf("잔돈 %d원을 반환하였습니다.\n음료를 꺼내주세요\n", coin - EIGHT);
      puts("--------------------------------------");
    }
    else
    {
      printf("음료를 꺼내주세요\n");
      puts("--------------------------------------");
    }
    rev[2] -= 1;
    break;
  case 4:
    if (coin < NINE)
    {
      printf("돈이 부족합니다. 동전을 반환합니다.\n");
      puts("--------------------------------------");
      coin = 0;
      return print(key, coin, num);
    }
    else if (coin > NINE)
    {
      printf("잔돈 %d원을 반환하였습니다.\n음료를 꺼내주세요\n", coin - NINE);
      puts("--------------------------------------");
    }
    else
    {
      printf("음료를 꺼내주세요\n");
      puts("--------------------------------------");
    }
    rev[3] -= 1;
    break;
  case 5:
    if (coin < NINE)
    {
      printf("돈이 부족합니다. 동전을 반환합니다.\n");
      puts("--------------------------------------");
      coin = 0;
      return print(key, coin, num);
    }
    else if (coin > NINE)
    {
      printf("잔돈 %d원을 반환하였습니다.\n음료를 꺼내주세요\n", coin - NINE);
      puts("--------------------------------------");
    }
    else
    {
      printf("음료를 꺼내주세요\n");
      puts("--------------------------------------");
    }
    rev[4] -= 1;
    break;
  case 6:
    if (coin < NINE)
    {
      printf("돈이 부족합니다. 동전을 반환합니다.\n");
      puts("--------------------------------------");
      coin = 0;
      return print(key, coin, num);
    }
    else if (coin > NINE)
    {
      printf("잔돈 %d원을 반환하였습니다.\n음료를 꺼내주세요\n", coin - NINE);
      puts("--------------------------------------");
    }
    else
    {
      printf("음료를 꺼내주세요\n");
      puts("--------------------------------------");
    }
    rev[5] -= 1;
    break;
  case 7:
    if (coin < TEN)
    {
      printf("돈이 부족합니다. 동전을 반환합니다.\n");
      puts("--------------------------------------");
      coin = 0;
      return print(key, coin, num);
    }
    else if (coin > TEN)
    {
      printf("잔돈 %d원을 반환하였습니다.\n음료를 꺼내주세요\n", coin - TEN);
      puts("--------------------------------------");
    }
    else
    {
      printf("음료를 꺼내주세요\n");
      puts("--------------------------------------");
    }
    rev[6] -= 1;
    break;
  case 8:
    if (coin < TEN)
    {
      printf("돈이 부족합니다. 동전을 반환합니다.\n");
      puts("--------------------------------------");
      coin = 0;
      return print(key, coin, num);
    }
    else if (coin > TEN)
    {
      printf("잔돈 %d원을 반환하였습니다.\n음료를 꺼내주세요\n", coin - TEN);
      puts("--------------------------------------");
    }
    else
    {
      printf("음료를 꺼내주세요\n");
      puts("--------------------------------------");
    }
    rev[7] -= 1;
    break;
  case 9:
    if (coin < TEN)
    {
      printf("돈이 부족합니다. 동전을 반환합니다.\n");
      puts("--------------------------------------");
      coin = 0;
      return print(key, coin, num);
    }
    else if (coin > TEN)
    {
      printf("잔돈 %d원을 반환하였습니다.\n음료를 꺼내주세요\n", coin - TEN);
      puts("--------------------------------------");
    }
    else
    {
      printf("음료를 꺼내주세요\n");
      puts("--------------------------------------");
    }
    rev[8] -= 1;
    break;
  }
  coin = 0;
  return print(key, coin, num);
}

// 재고 출력
int product(char key, int coin, int num)
{
  printf("펩시 재고: %d\n환타 재고: %d\n사이다 재고: %d\n", rev[0], rev[1], rev[2]);
  printf("알로에 재고: %d\n탄산수 재고: %d\n비타500 재고: %d\n", rev[3], rev[4], rev[5]);
  printf("딸기주스 재고: %d\n포도주스 재고: %d\n오렌지주스 재고:%d\n", rev[6], rev[7], rev[8]);
  puts("--------------------------------------");
  return print(key, coin, num);
}

// 재고 초기화
int reset(char key, int coin, int num)
{
  int i = 0;
  for (i = 0; i < 9; i++)
  {
    rev[i] = 10;
  }
  printf("매출이 초기화되었습니다.\n");
  puts("--------------------------------------");
  return print(key, coin, num);
}

// 메인실행
int main(void)
{
  int coin = 0, num = 0;
  char key = 'z';
  start(coin);
  print(key, coin, num);
  return 0;
}
