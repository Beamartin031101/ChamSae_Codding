#include<stdio.h>
#include<math.h>
#include<Windows.h>

int main() {

	int x = 10, y = 3;
	// ─ ┌ ┐ ┘ └


	for (int i = 0; i < x + 2; i++) {
		if (i == 0)
			printf("┌");
		else if (i == x + 1)
			printf("┐");
		else
			printf("─");
	}
	printf("\n");
	for (; y > 0; y--) {
		printf("│");
		for (int j = 0; j < x; j++) {
			printf(" ");
		}
		printf("│\n");
	}
	//함수를 선언하면 if문 추가하는 것으로 더 효율적인 코딩을 할 수 있지만, 원래는 for문도 사용하지 않아야 한다...
	for (int i = 0; i < x + 2; i++) {
		if (i == 0)
			printf("└");
		else if (i == x + 1)
			printf("┘");
		else
			printf("─");
	}
	//이 아래(텍스트 박스에 글자를 넣는 부분은 인터넷에서 코드를 참고해오겠다.)
	//Windows.h에 있는 SetConsoleCursorPosition 함수를 사용한다.

	printf("\n.");


	//지금은 이 수준에서 멈추지만 업그레이드도 어느정도 할 수 있을 듯하다
	COORD t;
	t.X = 2;
	t.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), t);
	printf("test");

	Sleep(10000);
	// -----결과-----
	// 우선 우려했던 문제인 밀려나기는 발생하지 않았다. 아마도 콘솔 좌표상의 공간에 덮어쓰기 하는 것 같다
	// 이상한 문제가 발생하였는데, 마지막 줄이 디버깅에서는 정상 작동하지만, 작성되지 않았다.
	// -----처방-----
	//우선 SetConsole....를 사용하기 전에 printf("\n");을 사용해보자.

	//-----결과 2-----
	 /*이상하게도, stdio.h에서 예외가 발생하였다(널포인터 에외인 것 같다)
	 디버깅에선 제대로 작성되다가 마지막 줄이 또 없어져버렸다.*/
	 //-----처방-----
	 //우선은 printf("\n."); 이렇게 고쳐보자. (내가 stdio를 고칠 수는 없으니까...)

	 //-----결과 3-----
	 /*정말 이상하다. 또 원하는 결과가 나오지 않았다. 해결할 수 없는 문제인 것일까?
		 어쩌면 모든 것이 끝나고 나오는 내용을 없앤다면 해결될 지도 모른다.*/
		 //-----처방-----
		 //sleep
}