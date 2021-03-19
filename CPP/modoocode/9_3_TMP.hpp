#ifndef TMP_9_3_HPP
#define TMP_9_3_HPP

/*
	<TMP 이해하기>
	서로 다른 템플릿 인자로 인스턴스화된 클래스는 (당연하게도) 서로 다른 타입이다.
	(ex) typeid(Array<int, 3>) != typeid(Array<int, 5>)
	TMP는 이러한 특성을 이용해 타입에 '값'을 부여하고 타입을 통해 '연산'을 할 수 있게 한다.

	타입은 반드시 컴파일 타임에 확정되어야 하므로 컴파일 타임에 모든 연산이 끝나게 된다.
	컴파일 타임보다 런타임 성능이 중요한 경우 TMP를 이용해 프로그램 실행 속도를 향상시킬 수 있다.
	단, 템플릿은 컴파일 타임에 타입이 확정되므로 디버깅이 매우 어렵고 에러 메시지도 길어지게 된다.
	따라서 TMP를 어떤 때 어떤 방식으로 사용하는지가 매우 중요하다.
*/

/*
	<value에 static const를 이용하는 이유>
	static const를 이용하면 같은 타입으로 만들어진 객체의 value가 모두 같은 값, 같은 참조를 가진다.
	이를 통해 GCD가 같은 템플릿 인자로 인스턴스화되면 그 객체들이 모두 같은 value를 갖게 된다.
*/
template <int X, int Y>
struct GCD
{
	static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0>
{
	static const int value = X;
};

template <int N, int D = 1>
struct Ratio
{
private:
	static const int _gcd = GCD<N, D>::value;

public:
	typedef Ratio<N / _gcd, D / _gcd> type; // 자기 자신을 가리키는 타입
	static const int num = N / _gcd;
	static const int den = D / _gcd;
};

template <class R1, class R2>
struct _Ratio_add
{
	typedef Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
	/*
	계산된 Ratio<resultN, resultD>을 가리키는 타입
	type은 해당 타입의 static const int인 num, den을 가지고 있으므로 호출할 수 있다.
	(ex) typedef _Ratio_add<rat, rat2>::type result;
	*/
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type
{
	// ::type 없이 Ratio_add를 사용하기 위한 빈 템플릿 구조체
};

template <class R1, class R2>
struct _Ratio_subtract
{
	typedef Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den> type;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type
{
};

template <class R1, class R2>
struct _Ratio_multiply
{
	typedef Ratio<R1::num * R2::num, R1::den * R2::den> type;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type
{
};

template <class R1, class R2>
struct _Ratio_divide
{
	typedef Ratio<R1::num * R2::den, R1::den * R2::num> type;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type
{
};

#endif
