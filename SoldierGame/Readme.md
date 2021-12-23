## **FULLNAME:**  

Phạm Huy Cường Thịnh

## **STUDENT'S ID:**

 20127335

## **ANY NOTICE ON HOW TO COMPILE AND RUN MY PROJECT ?**

- [x] Compiler: g++ 11.2.0 version

- [x] Text editor: Visual Studio Code

- [x] Operating system: Windows 11 version 21H2

- [x] C++ version: C++20

I also compiled and run my project on Visual Studio 2022 version and work perfectly.

## **WHAT I HAVE DONE:**

`READING TIME: 3 MIN READ`

I have created 17 classes for this homework. I used visitor design pattern and observer design pattern to handle this homework.

<img src="https://integu.net/wp-content/uploads/2020/11/INTEGU-visitor-design-pattern-overview-.png" width="300" height="180" /> <img src="https://laptrinhvb.net/uploads/source/vbnet/0umqa0oz6wf95h6aza4j.jpeg" width="300" height="180" />

- I created a **Character** class which is the abstract class of all characters and 3 inherited classes: **Swordman**, **Knight**, **Spikeman**.

- The class **IVisitor** is the visit pattern. It is used to visit all characters and print their information.

- The class **State** is the abstract class of all states. It is used to change the state of characters. It also has 4 inherited classes: **NormalState**, **ThreeSwordmanState**,  **ThreeKnightState**, **ThreeSpikemanState**.

- The next 6 classes are the observer design pattern. They are used to have some rules, create players, and start the game.
  
  - **Player** is the observer class. It is used to create players.

  - **Game** is the observer class. It is used to start the game.

  - **Rules** is the observer and abstract class. It is used to have some rules. It has 3 inherited classes:**ThreeSwordmanRules**, **ThreeKnightRules**, **ThreeSpikemanRules**.

- The last class is **RandomIntegerGenerator**. It is used to generate random integers in order to random the characters and choose which player attacks first.

In the main function, I created a **Game** object to start the game. First I print all the information of 2 teams. After 3 turns, the game will end and I print all the result of the game.

## **WHAT I HAVE NOT DONE:**

None.

## **WHAT SHOULD BE TAKEN INTO ACCOUNT FOR A BONUS ?**

I have created attack functions in 4 characters in order to make player attack each other.

## **EXPECTED GRADES:**

10.0
