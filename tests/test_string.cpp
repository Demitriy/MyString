#include "MyString.h"
#include <cassert>
#include <stdexcept>

void Test1() {
    String A;
    assert(*(A.data()) == '\0');
    assert(A.size() == 0);
    std::cout << "Test1 has been completed" <<std::endl;
}

void Test2() {
    char B[] = "Test2";
    String A(B);
    const char *pt = A.data();
    assert(A.size() == 5);
    for(unsigned i = 0; i <= A.size(); ++i) {
        assert(B[i] == *(pt++));
    }
    std::cout << "Test2 has been completed" <<std::endl;
}

void Test3() {
    char B[] = "Test3";
    String A(B, 5);
    const char *pt = A.data();
    assert(A.size() == 5);
    for(unsigned i = 0; i <= A.size(); ++i) {
        assert(B[i] == *(pt++));
    }
    std::cout << "Test3 has been completed" <<std::endl;
}

void Test4() {
    char B = 'q';
    String A(B, 10);
    const char *pt = A.data();
    assert(A.size() == 10);
    for(unsigned i = 0; i < A.size(); ++i) {
        assert(B == *(pt++));
    }
    assert('\0' == *pt);
    std::cout << "Test4 has been completed" <<std::endl;
}
 
void Test5() {
    String B("Test5");
    String A(B);
    assert(A.size() == B.size());
    for(unsigned i = 0; i <= A.size(); ++i) {
        assert(B[i] == A[i]);
    }
    std::cout << "Test5 has been completed" <<std::endl;
}

void Test6() {
    String B("Test6");
    String C(B);
    String A(std::move(B));
    assert(A.size() == C.size());
    for(unsigned i = 0; i <= A.size(); ++i) {
        assert(C[i] == A[i]);
    }
    assert(B.size() == 0);
    assert(*B.data() == '\0');
    std::cout << "Test6 has been completed" <<std::endl;
}

void Test_assigment1() {
    String A("Test_assigment1");
    String B, C;
    C = B = A;
    assert(A.size() == C.size());
    for(unsigned i = 0; i <= A.size(); ++i) {
        assert(C[i] == A[i]);
    }
    std::cout << "Test_assigment1 has been completed" <<std::endl;
}

void Test_assigment2() {
    String B("Test_assigment2");
    String C = B;
    String A = std::move(B);
    assert(A.size() == C.size());
    for(unsigned i = 0; i <= A.size(); ++i) {
        assert(C[i] == A[i]);
    }
    assert(B.size() == 0);
    assert(*B.data() == '\0');
    std::cout << "Test_assigment2 has been completed" <<std::endl;
}

void Test_plus_assigment_1() {
    char *res = "plus_assigment";
    String A("plus_");
    unsigned Asize = A.size();
    String B("assigment");
    unsigned Bsize = B.size();
    A += B;
    assert(A.size() == (Asize + Bsize));
    for(unsigned i = 0; i <= A.size(); ++i) {
        assert(res[i] == A[i]);
    }
    std::cout <<"Test_plus_assigment_1 has been completed" <<std::endl;
}

void Test_plus_assigment_2() {
    char *res = "plus_assigment";
    String C("plus_");
    unsigned Csize = C.size();
    char A[] = "assigment";
    unsigned Asize = 9;
    String B("plus_");
    unsigned Bsize = B.size();
    C += A;
    B += "assigment";
    assert((Asize + Csize) == C.size());
    assert(B.size() == (Asize + Bsize));
    assert(B.size() == C.size());
    for(unsigned i = 0; i <= C.size(); ++i) {
        assert(res[i] == C[i]);
        assert(res[i] == B[i]);
    }
    std::cout << "Test_plus_assigment_2 has been completed" <<std::endl;
}

void Test_plus_assigment_3() {
    char res[] = "plus_";
    String C("plus");
    unsigned Csize = C.size();
    char A = '_';
    unsigned Asize = 1;
    String B("plus");
    unsigned Bsize = B.size();
    C += A;
    B += '_';
    assert((Asize + Csize) == C.size());
    assert(B.size() == (Asize + Bsize));
    assert(B.size() == C.size());
    for(unsigned i = 0; i <= B.size(); ++i) {
        assert(res[i] == C[i]);
        assert(res[i] == B[i]);
    }
    std::cout << "Test_plus_assigment_3 has been completed" << std::endl;
}

void Test_index() {
    String A("Test");
    A[1] = 'a';
    char res[] = "Tast";
    for(unsigned i = 0; i <= A.size(); ++i) {
        assert(res[i] == A[i]);
    }
    std::cout << "Test_index has been completed" << std::endl;
}
void Test_swap() {
    char *res1 = "hgf";
    char *res2 = "lkjhgf";
    String A(res1);
    String B(res2);
    unsigned Asize = A.size();
    unsigned Bsize = B.size();
    A.swap(B);
    assert(Bsize = A.size());
    assert(Asize = B.size());
    for(unsigned i = 0; i <= A.size(); ++i) {
        assert(res2[i] == A[i]);
    }
    for(unsigned i = 0; i <= B.size(); ++i) {
        assert(res1[i] == B[i]);
    }
    std::cout << "Test_swap has been completed" << std::endl;
}

void Test_at() {
    const String A("Test_at");
    assert(A.at(3) == 't');
    try {
        const char x = A.at(10);
    }
    catch(const std::out_of_range &e) {
        std::cout << "Test_at has been completed" << std::endl;
        return;
    }
    std::cout << "Test_at has been failed" << std::endl;
}

/*void Test_equality() {
    String A("Test");
    String B(A);
    assert(A.size() == B.size());
    for(unsigned i = 0; i < A.size(); ++i) {
        assert(A[i] == B[i]);
    }
    std::cout << "Test_equality has been completed" << std::endl;
}

void Test_less() {
    String A("Test");
    String B(A);
    if (A < B) {
        std::cout << "Test_less has been failed 207" << std::endl;
    }
    B += "er";
    if (A < B) {
        std::cout << "Test_less has been failed 211" << std::endl;
    }
    std::cout << "Test_less has been completed" << std::endl;
}

void Test_plus_1() {
    String A("Test_");
    String B("plus_1");
    String C;
    String res("Test_plus_1");
    C = A + B;
    A = A + B;
    assert(C == res);
    assert(A == res);
    std::cout << "Test_plus_1 has been completed" << std::endl;
}

void Test_plus_2() {
    String A("Test_");
    char *B = "plus_1";
    String C;
    String res("Test_plus_1");
    C = A + B;
    A = A + B;
    assert(C == res);
    assert(A == res);
    std::cout << "Test_plus_2 has been completed" << std::endl;
}

void Test_plus_3() {
    String A("Test_");
    char *B = "plus_1";
    String C;
    String res("Test_plus_1");
    C = B + A;
    A = B + A;
    assert(C == res);
    assert(A == res);
    std::cout << "Test_plus_3 has been completed" << std::endl;
}

void Test_not_equality() {
    String A("kjh");
    String B("hgh");
    assert(!(A == B));
    std::cout << "Test_not_equlity has been completed" << std::endl;
}

void Test_less_equality() {
    String A("less");
    String B("equality");
    String C("less");
    if ((B <= A) && (A <= C)) {
        std::cout << "Test_less_equlity has been completed" << std::endl;
    } else {
        std::cout << "Test_less_equlity has been failed" << std::endl;
    }
}

void Test_more() {
    String A("more");
    String B ("aaaaa");
    if (A > B) {
        std::cout << "Test_more has been completed" << std::endl;
    } else {
        std::cout << "Test_more has been failed" << std::endl;
    }
}

void Test_more_equality() {
    String A("more");
    String B("more");
    String C("equality");
    if ((B >= A) && (A >= C)) {
        std::cout << "Test_more_equlity has been completed" << std::endl;
    } else {
        std::cout << "Test_more_equlity has been failed" << std::endl;
    }
}*/

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test_assigment1();
    Test_assigment2();
    Test_plus_assigment_1();
    Test_plus_assigment_2();
    Test_plus_assigment_3();
    Test_swap();
    Test_index();
    Test_at();
  /*  Test_equality();
    Test_less();
    Test_plus_1();
    Test_plus_2();
    Test_plus_3();
    Test_not_equality();
    Test_less_equality();
    Test_more();*/
    return 0;
}

