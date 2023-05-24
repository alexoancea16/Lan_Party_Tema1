# Lan_Party_Tema1
Tema 1 Proiectarea Algoritmilor - Lan Party - 

- Proiect realizat de: Oancea Constantin-Alexandru
- Student la: Facultatea de Automatica si Calculatoare (UPB), anul 1
- Data: 24.05.2023

Cerinta completa a temei poate fi accesata la adresa https://ocw.cs.pub.ro/courses/sda-ab/tema1

Problema: Facultatea de Automatica si Calculatoare prin LSAC organizeaza in fiecare semestru un LAN Party la care participa toti studentii care vor sa isi testeze abilitatile la un anumit joc. Se doreste realizarea unei solutii software (program executabil) ce poate automatiza acest proces.

Cerinte tehnice:

  - In realizarea proiectului s-a utilizat C ca limbaj de programare, astfel una dintre cerintele tehnice este  existenta unui compilator C. Un compilator popular si larg utilizat este GCC (GNU Compiler Collection), dar exista si alte optiuni disponibile pentru diferite sisteme de operare, cum ar fi Microsoft Visual C++ Compiler pentru Windows sau platforma de developare CodeBlocks (avand ca si compilator GNU GCC).
  - Cerinte de sitem: Windows sau Linux ca sistem de operare.
 
 Detalii tehnice:
 
   1. Programul este alcatuit din mai multe fisiere:
        - Header-ul "date.h", acest fișier trebuie inclus în fișierul sursa principal "main.c" si contine declaratiile structurilor si functiilor utilizate în program.
        - Fisierele sursa "main.c", "liste.c", "sdate.c" si "tree.c", fișierul "main.c" contine functia principala (main) si apeleaza celelalte functii definite în fisierele "liste.c", "sdate.c", "tree.c". 
        - Fisierele de intrare/iesire: programul utilizează fisiere pentru citirea datelor de intrare si pentru scrierea rezultatelor.
        - Fisierul c.in face referire la rezolvarea cerintlor acesta este important in cazul in care dorim sa utilizam un checker.
   2. Header-ul contine structurile necesare pentru a concentra si structura datele din fisirul "d.in".
   3. Fisierul "liste.c" contine functii specifice listelor simplu inlantuite (folosind diferite tipuri de date): addAtBeginning (adauga element la inceputul listei), addAtEnd (adauga element la finalul lisei), delete_elem (sterge element in functie de valoare), deleteList_Team (strege lista) sunt cateva exemple.
   4. In fisierul "sdate.c" se afla functiile necesare pentru implementarea operatiilor cu stive si cozi: createQueue (creare coada), enQueue (adaugare elemente in coada), deQueue (eliminare element din coada), deleteQueue (stergere coada), push (adaugare element in stiva), pop (sterge element din stiva), deleteStack (stergere stiva).
   5. Fisierul "tree.c" contine functii utilizate pentru operatii cu arbori binari: newNode (crearea unui nod nou), insert_n (inerarea unui nod nou in arbore), inorder (prcurgere arbore in inordine), nodeHight (calculeaza inaltimea arborelui), RightRotation, LeftRotation, LRRotation, RLRotation (functiile necesare echilibrarii arborelui), insert_avl (inserare nod intr-un arbore de tip AVL).
   6. Datele de intrare vor fi citite din fisierul d.in si vor fi afisate in fisierul r.out. 
   7. In programul principal s-a declarat variabila "head" care reprezinta capul listei simplu inlantuite care contine echipele de juctatori. O echipa este definita de structura Team care contine: numarul de participanti, numele echipei, scorul obtinut de aceasta, precum si detalii despre jucatori definte in structura player. Astfel s-a creat lista definita de structura care contine echipele. Prin intermediul functiei "create_team" sunt citite datele din fisier si sunt adaugate in lista cu ajutorul functiei "addAtEnd".
   8. In continuare este apelata functia procedurala "disqualified_team" care are rolul de elimina echipele pieratoare (cu punctaj minim) astfel incat sa ramana in lista un numar de echipe egal cu o putere a lui 2 pentru a putea realiza meciurile in continuare. Pentru aceasta s-a utilizat functia "nr_team_disqualified", alaturi de "points" si "min_points" pentru a gasi punctajele minime.
   9. Pentru a putea crea meciurile echipele si punctajul acestora au fost introduse in mod repetat intr-o coada (acasta a fost formata initial cu functia "create_MQueue", iar apoi in functia "fight" unde se creau cele doua stive: cea de castigatori si cea de piezatori. Repetarea procesului de adaugare eliminare elemente din stiva si introducerea acestora in stiva s-a realizat cu functia "create_Match_new". S-a tinut cont ca atunci cand raman 8 echipe in lista sa se formeze o lista simplu inlantuita care sa reprezinte top 8 cele mai bune echipe (pentru usurinta operatiilor s-a creat o noua structura "competitor" care retinea numele echipe si scorul optinut de aceasta). Iteratiile se finalizeaza cand se ajunge la echipa castigatoare.
   10. Mai departe topul celor 8 echipe a fost introdus intr-un arbore de tip BST. Aftfel lista creata a fost parcursa cu "create_top_classament" si fiecare element a fost inserat pe rand cu "insert_n". Prin parcuregerea arborelui in inordine ("inorder") a fost afisat clasamentul. Sturctura suplimentara adaugata este Node_tree specifica arborilor binari.
   11. Pentru crearea arborelul de tip AVL s-a folosit "extract_node" care nu este altceva decat o parcurgere in inordine a arborelui introducand pe rand cate un nod in AVL cu functia "insert_avl". In functia "insert_avl" au fost luate toate cazurile particulare realizandu-se diferite rotatii necesare pentru echilibrarea arborelui. Suplimentar se adauga structura Node_avl asemanatoare cu Node_tree, dar care are in plus inaltime nodului.
   12. Afisare in fisier a rezultatelor se face prin functiile de la inceputul fisierului "main.c" respectand cerintele impuse: "print_team", "print_fight", "print_winner", "print_top_team", "print_level".
   13. Pe parcursul programului au fost utilizate, de asemenea, functii pentru testarea diferitelor operatii cum ar fi: "open_fis", "isEmpty".
   14. La finalul programului a fost eliminata memoria ocupata in heap, fiind vorba de alocae dinamica, cu functiile "deleteList_Team" si "deleteList_Top".
   
Utilizarea programului: 

- se introduc datele in fisierul d.in conform cerintelor, iar rezulatele vor fi vizibile in fisierul r.out 
- utilitatea si functionalitatea programului poate fi vizualizata cu ajutorul instalarii checkeului aflat in cerinta temei.
    
Multumesc!

Oancea Constantin-Alexandru

Pentru detalii suplimentare pot fi contactat la adresa de email: alexandruoancea49@gmail.com
