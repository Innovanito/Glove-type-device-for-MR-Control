''' 레큘레이터가 내장되어 있기 때문에 아두이노 5V에 VCC를 연결하면 되고, RX와 TX를 각각 3번과 2번 포트에 연결한다.

다음에 아래와 같은 코드를 작성하여 실행한다.


위의 예제는 아두이노 콘솔에서 받은 명령을 ESP01 시리얼 포트로 전송하고 ESP01 에서 나온 결과값을 아두이노 콘솔에 출력하도록 하는 코드이다.ESP01의 디폴트 통신속도가 115200이기 때문에 mySerial.begin에서 통신 속도를 115200으로 설정하였다.(추후 바꿀것이다.)

    를 실행해서 AT 명령을 실행해보자.연결이 제대로 되었으면 아래와 그림과 같이 OK 응답이 오는 것을 볼 수 있다. 
'''

#include <SoftwareSerial.h>

    SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{

  Serial.begin(9600);

  mySerial.begin(115200);
}

void loop()
{

  if (mySerial.available())
  {

    Serial.write(mySerial.read());
  }

  if (Serial.available())
  {

    mySerial.write(Serial.read());
  }
}


