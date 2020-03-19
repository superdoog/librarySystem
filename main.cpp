#include <iostream>
#include <iomanip>
using namespace std;

struct book
{
    string name;        // 书名
    int num;            // 书籍编码
    string author;      // 作者
    string kind;        // 种类
    int total;          // 这本书总共数量
    int number;         // 现存量
    book *next;
} *head = NULL, *p1, *p2;

int n = 0; //书籍链表长

struct lend {
    int num;            // 借书记录号
    int Id;             // 图书证号
    int bookNum;        // 书籍编码
    string date;        // 归还日期
    lend *next;
} *lendList = NULL, *q1, *q2;

int m = 0; //借书记录表长


/**
 * 增加书籍
 * @return
 */
book *creat()    //建立链表
{
    p1 = new(book);            //开辟动态内存存储空间存放新结点
    cout << "请输入要增加的书籍编号，输入为0时停止输入: ";
    cin >> p1->num;

    while (p1->num != 0) {
        int i = 0;
        n++;
        if (n == 1)
            head = p1;            //第一个结点赋给头结点
        else
            p2->next = p1;     //往下链接新建立的结点
        cout << "请输入书籍名字：";
        cin >> p1->name;
        cout << "请输入书籍作者：";
        cin >> p1->author;
        cout << "请输入书籍种类：";
        cin >> p1->kind;
        cout << "请输入要添加该书籍数目：";
        cin >> i;
        p1->total = i;
        p1->number = i;
        p2 = p1;
        cout << "请输入要增加的书籍编号，输入为0时停止输入: ";
        p1 = new(book);        //继续开辟动态内存存储空间存放新结点
        cin >> p1->num;
    }
    cout << endl << endl;
    delete p1;                  //停止建立新结点  
    p2->next = NULL;
    return head;
}

/**
 * 借阅
 * @param bookNum 书籍编码
 * @return
 */
lend *creatLend(int bookNum) {
    q1 = new(lend);            //开辟动态内存存储空间存放新结点
    cout << "请输入借书记录号: ";
    cin >> q1->num;
    m++;
    if (m == 1)
        lendList = q1;            //第一个结点赋给头结点
    else
        q2->next = q1;     //往下链接新建立的结点
    cout << "请输入图书证号：";
    cin >> q1->Id;
    q1->bookNum = bookNum;
    cout << "请输入归还日期：";
    cin >> q1->date;
    q2 = q1;
    cout << endl << endl;
    delete q1;
    q2->next = NULL;
    return lendList;
}

/**
 * 输出书籍信息
 * @param head
 */
void print(book *head)
{
    book *p;
    p = head;
    if (p == NULL) {
        cout << "书库里没有书籍! " << endl;
        return;
    }
    cout << "目前书库所含书籍信息为：" << endl
            << "编号" << "     " << "名字" << "     "
            << "作者" << "     " << "种类" << "     "
            << "总量" << "       " << "现量" << endl;
    do {
        cout << p->num << setw(10)  << p->name << setw(7)
             << p->author << setw(10) << p->kind << setw(8)
             << p->total << setw(10) << p->number << endl;
        p = p->next;
    } while (p != NULL);

}

/**
 * 输出借阅记录
 * @param lendList
 */
void printLendList(lend *lendList)
{
    lend *p;
    p = lendList;
    if (p == NULL) {
        cout << "无借阅记录! " << endl;
        return;
    }
    cout << "目前借阅记录为：" << endl
         << "借阅记录号" << "      " << "图书证号" << "        "
         << "书籍编号" << "        " << "归还日期" << endl;
    do {
        cout << p->num << setw(16) << p->Id << setw(16)
             << p->bookNum << setw(20) << p->date << endl;
        p = p->next;
    } while (p != NULL);

}

/**
 * 增加已有书籍数量
 * @param head
 */
void addBook(book *head) {
    book *p1, *p2;
    int num;
    int addNum;
    if (head == NULL)
    {
        cout << "书库里没有书籍!" << endl;
    }
    cout << "请输入要增加的书籍的编码：" << endl;
    cin >> num;
    p1 = head;
    while (num != p1->num && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if (num == p1->num)
    {
        cout << "请输入增加的数量：";
        cin >> addNum;
        p1->number += addNum;
        p1->total += addNum;
        cout << "增加数量成功。";
    } else
        cout << "不存在该编号的书籍" << endl << endl;


}

/**
 * 删除书籍
 * @param head
 * @return
 */
book *del(book *head)         //删除结点  
{
    book *p1, *p2;
    int num;
    if (head == NULL)          //如果原先链表为空
    {
        cout << "书库里没有书籍!" << endl;
        return head;
    }
    cout << "请输入要删除书籍的编码：" << endl;
    cin >> num;
    p1 = head;
    while (num != p1->num && p1->next != NULL)     //找不到相应的结点就往下继续搜索
    {
        p2 = p1;
        p1 = p1->next;
    }
    if (num == p1->num)         //找到结点
    {
        if (p1 == head)            //结点是第一位
            head = p1->next;
        else                    //结点不是第一位
            p2->next = p1->next;
        cout << "删除成功" << endl << endl;
        n--;
        print(head);
    } else
        cout << "不存在该编号的书籍" << endl << endl;
    return head;
}

/**
 * 删除借阅记录
 * @param lendList
 * @param num 借阅记录号
 * @return
 */
lend *delLend(lend *lendList, int num)         //删除结点
{
    lend *q1, *q2;
    if (lendList == NULL)          //如果原先链表为空
    {
        cout << "无借阅记录!" << endl;
        return lendList;
    }
    q1 = lendList;
    while (num != q1->num && q1->next != NULL)     //找不到相应的结点就往下继续搜索
    {
        q2 = q1;
        q1 = q1->next;
    }
    if (num == q1->num)         //找到结点
    {
        if (q1 == lendList)            //结点是第一位
            lendList = q1->next;
        else                    //结点不是第一位
            q2->next = q1->next;
        cout << "还书成功!" << endl << endl;
        n--;
    } else
        cout << "不存在该记录!" << endl << endl;
    return lendList;
}

/**
 * 通过书籍标编号查询书籍
 * @param head
 */
void find_num(book *head) {
    book *p1;
    int num;
    cout << "请输入要查询的书籍编号：" << endl;
    cin >> num;
    if (head == NULL)          //如果原先链表为空
    {
        cout << "书库里没有书籍!" << endl;
        return;
    }
    p1 = head;
    while (num != p1->num && p1->next != NULL)     //找不到相应的结点就往下继续搜索
    {
        p1 = p1->next;
    }
    if (num == p1->num)         //找到结点
    {
        cout << "查找到的书籍信息为：" << endl
             << "编号" << "     " << "名字" << "     "
             << "作者" << "     " << "种类" << "     "
             << "总量" << "       " << "现量" << endl;
        cout << p1->num << setw(10) << p1->name << setw(7)
             << p1->author << setw(10) << p1->kind << setw(8)
             << p1->total << "        " << p1->number << endl;
    } else
        cout << "找不到该书籍!" << endl << endl;

}

/**
 * 通过书名查询书籍
 * @param head
 */
void find_name(book *head) {
    book *p1;
    string name;
    cout << "请输入要查询的书籍名字：" << endl;
    cin >> name;

    if (head == NULL)          //如果原先链表为空
    {
        cout << "书库里没有书籍!" << endl;
        return;
    }
    p1 = head;
    while (name.compare(p1->name) != 0 && p1->next != NULL)     //找不到相应的结点就往下继续搜索
    {
        p1 = p1->next;
    }
    if (name.compare(p1->name) == 0)         //找到结点
    {
        cout << "查找到的书籍信息为：" << endl
             << "编号" << "     " << "名字" << "     "
             << "作者" << "     " << "种类" << "     "
             << "总量" << "       " << "现量" << endl;
        cout << p1->num << setw(10) << p1->name << setw(7)
             << p1->author << setw(10) << p1->kind << setw(8)
             << p1->total << "        " << p1->number << endl;
    } else
        cout << "找不到该书籍!" << endl << endl;

}

/**
 * 借书
 * @param head
 * @return
 */
book *borrow(book *head) {

    if (head == NULL)          //如果原先链表为空
    {
        cout << "书库里没有书籍!" << endl;
        return head;
    }
    cout << "请输入要借阅书籍的名称：" << endl;
    string name;
    cin >> name;
    book *p1;
    p1 = head;
    while (name.compare(p1->name) != 0 && p1->next != NULL)     //找不到相应的结点就往下继续搜索
    {
        p1 = p1->next;
    }
    if (name.compare(p1->name) == 0)         //找到结点
    {
        cout << "查找到的书籍信息为：" << endl
             << "编号" << "     " << "名字" << "     "
             << "作者" << "     " << "种类" << "     "
             << "总量" << "       " << "现量" << endl;
        cout << p1->num << setw(10) << p1->name << setw(7)
             << p1->author << setw(10) << p1->kind << setw(8)
             << p1->total << "        " << p1->number << endl;
        if (p1->number != 0) {
            cout << "确定要借阅该书籍吗？" << endl
                 << "1.确定" << '\t' << "2.取消" << endl;
            int num;
            cin >> num;
            switch (num) {
                case 1:
                    creatLend(p1->num);
                    (p1->number)--;
                    cout << "借阅成功!" << endl;
                    break;
                case 2:
                    break;
                default:
                    cout << "输入有误!" << endl;
                    break;
            }
        } else
            cout << "书籍已全被借阅!" << endl;
    } else
        cout << "找不到该书籍!" << endl << endl;


    return head;

}

/**
 * 还书
 * @param head
 * @return
 */
book *back(book *head) {

    if (head == NULL)          //如果原先链表为空
    {
        cout << "书库未借出过任何书籍! " << endl;
        return head;
    }
    if (lendList == NULL) {
        cout << "书库未借出过任何书籍! " << endl;
        return head;
    }
    cout << "请输入要归还书籍的名称：" << endl;
    string name;
    cin >> name;
    book *p1;
    p1 = head;
    while (name.compare(p1->name) != 0 && p1->next != NULL)     //找不到相应的结点就往下继续搜索
    {
        p1 = p1->next;
    }
    if (name.compare(p1->name) == 0)         //找到结点
    {

        cout << "确定要归还该书籍吗？" << endl
             << "1.确定" << '\t' << "2.取消" << endl;
        int num;
        cin >> num;
        switch (num) {
            case 1:
                int recordNum;
                cout << "请输入要删除的借阅记录号：" << endl;
                cin >> recordNum;
                lendList = delLend(lendList, recordNum);
                (p1->number)++;
                break;
            case 2:
                break;
            default:
                cout << "输入有误!" << endl;
                break;
        }

    } else
        cout << "不存在该书籍!" << endl << endl;

    return head;

}

/**
 * 查询菜单
 */
void find() {
    int num;
    cout << "	***************************************************" << endl;
    cout << "	*           请输入对应功能的数字完成操作              *" << endl;
    cout << "	*                 1.通过编号查找                    *" << endl;
    cout << "	*                 2.通过书名查找                    *" << endl;
    cout << "	***************************************************" << endl;
    cin >> num;
    switch (num) {
        case 1:
            find_num(head);
            break;
        case 2:
            find_name(head);
            break;
        default:
            cout << "输入有误!" << endl;
            break;
    }
}

/**
 * 管理菜单
 */
void manage() {
    int num1;
    cout << "请输入管理员密码(123456)：" << endl;
    cin >> num1;
    if (num1 == 123456) {
        int num;
        cout << "	***************************************************" << endl;
        cout << "	*           请输入对应功能的数字完成操作              *" << endl;
        cout << "	*                     1.增加书籍                   *" << endl;
        cout << "	*                     2.增加已有书籍                *" << endl;
        cout << "	*                     3.删除书籍                   *" << endl;
        cout << "	***************************************************" << endl;
        cin >> num;
        switch (num) {
            case 1:
                head = creat();
                print(head);
                break;
            case 2:
                addBook(head);
                print(head);
                break;
            case 3:
                head = del(head);
                break;
            default:
                cout << "输入有误!" << endl;
                break;
        }
    } else
        cout << "输入错误，你没有权限修改图书管理系统!" << endl;
}

/**
 * 界面
 */
void display() {
    cout << "	***************************************************" << endl;
    cout << "	*           请输入对应功能的数字完成操作             *" << endl;
    cout << "	*                     1.查询                      *" << endl;
    cout << "	*                     2.借书                      *" << endl;
    cout << "	*                     3.还书                      *" << endl;
    cout << "	*                     4.管理                      *" << endl;
    cout << "	*                     5.书库                      *" << endl;
    cout << "	*                     6.借阅记录                  *" << endl;
    cout << "	*                     7.退出                      *" << endl;
    cout << "	***************************************************" << endl;
}

int main() {
    int choice = 1;
    while (choice != 0) {
        display();
        cin >> choice;
        switch (choice) {
            case 1:
                find();
                break;
            case 2:
                head = borrow(head);
                break;
            case 3:
                head = back(head);
                break;
            case 4:
                manage();
                break;
            case 5:
                print(head);
                break;
            case 6:
                printLendList(lendList);
                break;
            case 7:
                choice = 0;
                break;
            default:
                cout << "输入有误，请重新输入!" << endl;
                break;

        }
    }
    cout << "	***************************************************" << endl;
    cout << "	*                                                 *" << endl;
    cout << "	*                  感谢您的使用！                   *" << endl;
    cout << "	*                                                 *" << endl;
    cout << "	***************************************************" << endl;

    return 0;
}
