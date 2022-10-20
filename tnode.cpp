#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode
{
    int NilaiX;
    int NilaiY;
    string target;
    TNode *next;
};

TNode *head, *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

int isEmpty()
{
    if (tail == NULL)
        return 1;
    else
        return 0;
}

/*void insert(int databaru1, int databaru2, string target)
{
    TNode *baru, *bantu;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target = target;
    if (head == NULL)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        bantu = head;
        do
        {
            if (baru->NilaiX < bantu->NilaiX)
            {
                baru->next = head;
                head = baru;
                break;
            }
            else if (baru->NilaiX > tail->NilaiX)
            {
                tail->next = baru;
                tail = baru;
                break;
            }
            else if (baru->NilaiX > bantu->NilaiX && baru->NilaiX < bantu->next->NilaiX)
            {
                baru->next = bantu->next;
                bantu->next = baru;
                break;
            }
            else
            {
                bantu = bantu->next;
            }

        } while (bantu != NULL);
    }
    cout << "Data masuk\n";
}
*/

void insertDepan(int databaru1, int databaru2, string target)
{
    TNode *baru;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target = target;
    baru->next = NULL;
    if (isEmpty() == 1)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
    cout << "Data masuk\n";
}

void insertBelakang(int databaru1, int databaru2, string target)
{
    TNode *baru;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target = target;
    baru->next = NULL;
    if (isEmpty() == 1)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
    cout << "Data masuk\n";
}

void insertAfter(int databaru1, int databaru2, string target)
{
    TNode *baru, *bantu;
    int ke1;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target = target;
    baru->next = NULL;
    if (isEmpty() == 1)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        cout << "Insert Setelah Nilai X = ";
        cin >> ke1;
        bantu = head;
        do
        {
            if (ke1 == tail->NilaiX)
            {
                tail->next = baru;
                tail = baru;
            }

            else if (ke1 == bantu->NilaiX)
            {
                baru->next = bantu->next;
                bantu->next = baru;
            }
            bantu = bantu->next;
        } while (bantu != NULL);
    }
    cout << "Data masuk\n";
}

void insertBefore(int databaru1, int databaru2, string target)
{
    TNode *baru, *bantu;
    int ke1;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target = target;
    baru->next = NULL;
    if (isEmpty() == 1)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        cout << "Insert Sebelum Nilai X = ";
        cin >> ke1;
        bantu = head;
        do
        {
            if (ke1 == bantu->next->NilaiX)
            {
                baru->next = bantu->next;
                bantu->next = baru;
                break;
            }
            bantu = bantu->next;
        } while (bantu != NULL);
    }
    cout << "Data masuk\n";
}

void caridata()
{
    TNode *bantu;
    if (head != NULL)
    {
        int ke1;
        string target;
        cout << "Cari Nilai X berapa = ";
        cin >> ke1;
        cout << "Cari String Target apa = ";
        cin >> target;
        bantu = head;
        // cout << "head " << bantu->NilaiY;
        do
        {
            if (ke1 == bantu->NilaiX && target == bantu->target)
            {
                cout << "ketemu..." << endl;
                break;
            }
            else
            {
                bantu = bantu->next;
            }

        } while (bantu != NULL);
    }
    else
    {
        cout << "Koossoongg" << endl;
    }
}

void tampil()
{
    TNode *bantu;
    bantu = head;
    if (head != NULL)
    {
        while (bantu != NULL)
        {
            cout << bantu->NilaiX << " " << bantu->NilaiY << " " << bantu->target << " ";
            bantu = bantu->next;
        }
    }
    else
    {
        cout << "KOOSONGG" << endl;
    }
}

void hapusDepan()
{

    TNode *hapus;
    int x;
    int y;
    string t;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = head;
            x = hapus->NilaiX;
            head = head->next;
            delete hapus;
        }
        else
        {
            x = tail->NilaiX;
            y = tail->NilaiY;
            t = tail->target;
            head = tail = NULL;
        }
        cout << x << " " << y << " " << t << " terhapus";
    }
    else
        cout << "Masih kosong\n";
}

void hapusBelakang()
{
    TNode *bantu, *hapus;
    int d;
    if (head == NULL)
    {
        cout << "KOOOSSOONGG" << endl;
    }
    else
    {
        if (head != tail)
        {
            bantu = head;
            hapus = tail;
            do
            {
                if (bantu->next->NilaiX == tail->NilaiX)
                {
                    tail = bantu;
                    tail->next = NULL;
                    delete hapus;
                    break;
                }
                bantu = bantu->next;
            } while (bantu != NULL);
        }
        else
        {
            cout << head->NilaiX << " " << tail->NilaiX << endl;
        }
    }
}
void hapusTengah()
{
    TNode *hapus, *bantu;
    int ke1;
    int y;
    string t;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            bantu = head;
            cout << "Cari Nilai X berapa = ";
            cin >> ke1;
            do
            {
                if (ke1 == bantu->next->NilaiX)
                {
                    hapus = bantu->next;
                    bantu->next = bantu->next->next;
                    delete hapus;
                    break;
                }
                else
                    bantu = bantu->next;

            } while (bantu != NULL);
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
        cout << "Masih kosong\n";
}

void clear()
{
    TNode *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = NULL;
    printf("clear");
}

int main()
{
    int pil, databaru1, databaru2;
    string target;
    do
    {
        cout << endl;
        cout << " ============================" << endl;
        cout << " =   PROGRAM LINKED LIST    =" << endl;
        cout << " ============================" << endl;
        // cout << " = 1. Insert Urut Angka     =" << endl;
        cout << " = 2. Insert Depan          =" << endl;
        cout << " = 3. Insert Belakang       =" << endl;
        cout << " = 4. Insert After          =" << endl;
        cout << " = 5. Insert Before         =" << endl;
        cout << " = 6. Hapus depan           =" << endl;
        cout << " = 7. Hapus Belakang        =" << endl;
        cout << " = 8. Hapus Tengah          =" << endl;
        cout << " = 9. Cari Data             =" << endl;
        cout << " = 10. Tampil Data           =" << endl;
        cout << " = 11. Clear                =" << endl;
        cout << " = 12. Exit                 =" << endl;
        cout << " ============================" << endl;
        cout << " Masukan Pilihan : ";
        cin >> pil;
        switch (pil)
        {
        /*case 1:
        {
            cout << "Masukan Nilai X = ";
            cin >> databaru1;
            cout << "Masukan Nilai Y = ";
            cin >> databaru2;
            cout << "Masukan String Target = ";
            cin >> target;
            insert(databaru1, databaru2, target);
            break;
        }*/
        case 2:
        {
            cout << "Masukan Nilai X = ";
            cin >> databaru1;
            cout << "Masukan Nilai Y = ";
            cin >> databaru2;
            cout << "Masukan String Target = ";
            cin >> target;
            insertDepan(databaru1, databaru2, target);
            break;
        }
        case 3:
        {
            cout << "Masukan Nilai X = ";
            cin >> databaru1;
            cout << "Masukan Nilai Y = ";
            cin >> databaru2;
            cout << "Masukan String Target = ";
            cin >> target;
            insertBelakang(databaru1, databaru2, target);
            break;
        }
        case 4:
        {
            cout << "Masukan Nilai X = ";
            cin >> databaru1;
            cout << "Masukan Nilai Y = ";
            cin >> databaru2;
            cout << "Masukan String Target = ";
            cin >> target;
            insertAfter(databaru1, databaru2, target);
            break;
        }
        case 5:
        {
            cout << "Masukan Nilai X = ";
            cin >> databaru1;
            cout << "Masukan Nilai Y = ";
            cin >> databaru2;
            cout << "Masukan String Target = ";
            cin >> target;
            insertBefore(databaru1, databaru2, target);
            break;
        }
        case 6:
        {
            hapusDepan();
            break;
        }
        case 7:
        {
            hapusBelakang();
            break;
        }
        case 8:

        {
            hapusTengah();
            break;
        }
        case 9:

        {
            caridata();
            break;
        }
        case 10:

        {
            tampil();
            break;
        }
        case 11:
        {
            clear();
            break;
        }
        case 12:
        {
            return 0;
            break;
        }
        default:
        {
            cout << "\n Maaf, Pilihan yang anda pilih tidak tersedia!";
        }
        }
        getch();
        system("cls");
    } while (pil != 12);
    return 0;
}