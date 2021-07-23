#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<limits>
using namespace std;

enum CategoryMagazine {
  SCI,
  SCIE,
  ISI,
  SCOPUS,
  ETC
};
string enumStr[] = {"SCI", "SCIE", "ISI", "SCOPUS", "ETC"};
enum SizeCol {
  COL1 = 11,
  COL2 = 13,
  COL3 = 13,
  COL4 = 14,
  COL5 = 13,
  COL6 = 14,
  COL7 = 14,
  COL8 = 18,
  COL9 = 20,
};
typedef enum SizeCol SizeCol;

template <class TypeNode>
class Helper {
  public:
    void readFileToScreen(string fileName) {
      ifstream file(fileName);

      string text;
      while (getline(file, text)) {
        cout << text + "\n";
      }
      cout << endl;
    }
};

struct articleTile {
  string code_article_title;
  string name_article_title;
  string name_magazine_title;
  string category_magazine_title;
  string number_publish_title;
  string episode_publish_title;
  string year_publish_title;
  string company_publish_title;
  string author_title;
  bool created = false;
  void create(ifstream &file) {
    getline(file, this->code_article_title, '|');
    getline(file, this->name_article_title, '|');
    getline(file, this->name_magazine_title, '|');
    getline(file, this->category_magazine_title, '|');
    getline(file, this->number_publish_title, '|');
    getline(file, this->episode_publish_title, '|');
    getline(file, this->year_publish_title, '|');
    getline(file, this->company_publish_title, '|');
    getline(file, this->author_title);
    this->created = true;
  }

  void show() {
    cout << this->code_article_title << "|";
    cout << this->name_article_title << "|";
    cout << this->name_magazine_title << "|";
    cout << this->category_magazine_title << "|";
    cout << this->number_publish_title << "|";
    cout << this->episode_publish_title << "|";
    cout << this->year_publish_title << "|";
    cout << this->company_publish_title << "|";
    cout << this->author_title << "\n";
  }
};
typedef struct articleTile ArticleTile;

class Article {
  private:
    string code_article;
    string name_article;
    string name_magazine;
    CategoryMagazine category_magazine;
    string number_publish;
    string episode_publish;
    string year_publish;
    string company_publish;
    string author;

  public:
    Article(){};

    Article(string code_article, string name_article, string name_magazine, CategoryMagazine category_magazine,
            string number_publish, string episode_publish, string year_publish, string company_publish, string author) {
      this->code_article = code_article;
      this->name_article = name_article;
      this->name_magazine = name_magazine;
      this->category_magazine = category_magazine;
      this->number_publish = number_publish;
      this->episode_publish = episode_publish;
      this->year_publish = year_publish;
      this->company_publish = company_publish;
      this->author = author;
    }

    void setCodeArticle(string code_article) {
      this->code_article = code_article;
    }
    string getCodeArticle() {
      return this->code_article;
    }

    void setNameArticle(string name_article) {
      this->name_article = name_article;
    }
    string getNameArticle() {
      return this->name_article;
    }

    void setNameMagazine(string name_magazine) {
      this->name_magazine = name_magazine;
    }
    string getNameMagazine() {
      return this->name_magazine;
    }

    void setCategoryMagazine(CategoryMagazine category_magazine) {
      this->category_magazine = category_magazine;
    }
    string getCategoryMagazine() {
      return enumStr[this->category_magazine];
    }

    void setNumberPublish(string number_publish) {
      this->number_publish = number_publish;
    }
    string getNumberPublish() {
      return this->number_publish;
    }

    void setEpisodePublish(string year_publish) {
      this->year_publish = year_publish;
    }
    string getEpisodePublish() {
      return this->episode_publish;
    }

    void setYearPublish(string company_publish) {
      this->company_publish = company_publish;
    }
    string getYearPublish() {
      return this->year_publish;
    }

    void setCompanyPublish(string company_publish) {
      this->company_publish = company_publish;
    }
    string getCompanyPublish() {
      return this->company_publish;
    }

    void setAuthor(string author) {
      this->author = author;
    }
    string getAuthor() {
      return this->author;
    }

    Article *createFromFile(ifstream &articleDataFile) {
      getline(articleDataFile, this->code_article, '|');
      getline(articleDataFile, this->name_article, '|');
      getline(articleDataFile, this->name_magazine, '|');

      // convert string to Enum
      string categoryMagazine;
      getline(articleDataFile, categoryMagazine, '|');
      this->category_magazine = this->convertStrToEnumCategory(categoryMagazine);

      getline(articleDataFile, this->number_publish, '|');
      getline(articleDataFile, this->episode_publish, '|');
      getline(articleDataFile, this->year_publish, '|');
      getline(articleDataFile, this->company_publish, '|');
      getline(articleDataFile, this->author);
      return this;
    }

    Article *createFromScreen() {
      cout << "Mã bài báo : ";
      cin >> this->code_article;
      cout << "Tên bài báo: ";
      cin >> this->name_article;
      cout << "Tên bài báo: ";
      cin >> this->name_magazine;
      cout << "Loại tạp chí: ";

      string category;
      cin >> category;
      this->category_magazine = this->convertStrToEnumCategory(category);

      cout << "Số xuất bản: ";
      cin >> this->number_publish;
      cout << "Tập xuất bản: ";
      cin >> this->episode_publish;
      cout << "Năm xuất bản: ";
      cin >> this->year_publish;
      cout << "Công ty xuất bản: ";
      cin >> this->company_publish;
      cout << "Tác giả: ";
      cin >> this->author;

      return this;
    }

    Article *show() {
      cout << this->createSpaceWithStr(this->getCodeArticle(), COL1, 0) << "|";
      cout << this->createSpaceWithStr(this->getNameArticle(), COL2) << "|";
      cout << this->createSpaceWithStr(this->getNameMagazine(), COL3) << "|";
      cout << this->createSpaceWithStr(this->getCategoryMagazine(), COL4) << "|";
      cout << this->createSpaceWithStr(this->getNumberPublish(), COL5) << "|";
      cout << this->createSpaceWithStr(this->getEpisodePublish(), COL6) << "|";
      cout << this->createSpaceWithStr(this->getYearPublish(), COL7) << "|";
      cout << this->createSpaceWithStr(this->getCompanyPublish(), COL8) << "|";
      cout << this->createSpaceWithStr(this->getAuthor(), COL9) << "\n";

      return this;
    }

    Article *update(int numberCase) {
      string data;
      cout << "value: ";
      cin >> data;
      switch (numberCase) {
        case 1:
          this->setCodeArticle(data);
          break;
        case 2:
          this->setNameArticle(data);
          break;
        case 3:
          this->setNameMagazine(data);
          break;
        case 4: {
          CategoryMagazine categoryMagazine = this->convertStrToEnumCategory(data);
          this->setCategoryMagazine(categoryMagazine);
          break;
        }
        case 5:
          this->setNumberPublish(data);
          break;
        case 6:
          this->setEpisodePublish(data);
          break;
        case 7:
          this->setYearPublish(data);
          break;
        case 8:
          this->setCompanyPublish(data);
          break;
        case 9:
          this->setAuthor(data);
          break;
        default:
          cout << "Can't update article with your selected";
      }

      return this;
    }

    string toString() {
      return this->getCodeArticle() + '|'
        + this->getNameArticle() + '|'
        + this->getNameMagazine() + '|'
        + this->getCategoryMagazine() + '|'
        + this->getNumberPublish() + '|'
        + this->getEpisodePublish() + '|'
        + this->getYearPublish() + '|'
        + this->getCompanyPublish() + '|'
        + this->getAuthor() +  '\n';
    }

    private:
      void createSpace(string &str, int numSpace) {
        while (str.length() < numSpace) {
          str += " ";
        }
      }

      string createSpaceWithStr(string content, int totalSpace, int numSpaceLeft = 1) {
        string spaceRight = "";
        string spaceLeft = "";
        int numSpaceRight = totalSpace - numSpaceLeft - content.length();

        this->createSpace(spaceRight, numSpaceRight);
        this->createSpace(spaceLeft, numSpaceLeft);

        return spaceLeft + content + spaceRight;
      }

      CategoryMagazine convertStrToEnumCategory(string str) {
        for (int i = SCI; i != SCOPUS; i++) {
          if (str == enumStr[i]) {
            CategoryMagazine category = static_cast<CategoryMagazine>(i);
            return category;
          }
        }
        return ETC;
      }
};

class ArticleNode {
  public:
    Article *article;
    ArticleNode *pNext;

  public:
    ArticleNode(Article *article = new Article()) {
      this->article = article;
      this->pNext = NULL;
    }

    bool compareBy(ArticleNode *other, string type, string direction = "asc") {
      if(type == "name_article") return this->compareArticleName(other, direction);

      if(type == "year_publish") return this->compareYearPublish(other, direction);

      return false;
    }

    bool findArticleBy(string type, string other) {
      if (type == "code_article") return this->findByArticleCode(other);
      if (type == "name_article") return this->findByArticleName(other);
      if (type == "year_publish") return this->findByYearPublish(other);
      if (type == "author") return this->findByAuthor(other);

      return false;
    }
    bool isCheckArticleEmpty() {
      return this->article->getCodeArticle() == "";
    }

  private:
    bool compareArticleName(ArticleNode *other, string direction) {
      return this->compareTwoStr(this->article->getNameArticle(), other->article->getNameArticle(), direction);
    }
    bool compareYearPublish(ArticleNode *other, string direction) {
      return this->compareTwoStr(this->article->getYearPublish(), other->article->getYearPublish(), direction);
    }

    bool findByArticleCode(string other) {
      return this->containsStr(this->article->getCodeArticle(), other);
    }
    bool findByArticleName(string other) {
      return this->containsStr(this->article->getNameArticle(), other);
    }
    bool findByYearPublish(string other) {
      return this->containsStr(this->article->getYearPublish(), other);
    }
    bool findByAuthor(string other) {
      return this->containsStr(this->article->getAuthor(), other);
    }

    bool compareTwoStr(string a, string b, string direction) {
      int result = a.compare(b);
      if (direction == "desc" && (!~result || !result))
        return true;
      if (direction == "asc" && (result > 0))
        return true;

      return false;
    }

    bool containsStr(string a, string b) {
      return a.find(b) != string::npos;
    }
};


class ArticleList {
  private:
    ArticleNode *articleHead, *articleTail;
    ArticleTile titles;

  public:
    ArticleList() {
      this->articleHead = NULL;
      this->articleTail = NULL;
    }
    ArticleList(string fileArticles) {
      this->articleHead = NULL;
      this->articleTail = NULL;
      this->createListFromFile(fileArticles);
    }

    ArticleNode *createArticleNode(Article *article = new Article()) {
      ArticleNode *articleNode = new ArticleNode(article);
      return articleNode;
    }

    ArticleList *createListFromFile(string fileName) {
      ifstream articlesFile(fileName);

      this->titles.create(articlesFile);

      while (!articlesFile.eof()) {
        Article *article = new Article();
        this->pushArticle(article->createFromFile(articlesFile));
      }

      articlesFile.close();

      return this;
    }

    // Add to the top list
    ArticleList *unshiftArticle(Article *article) {
      ArticleNode *articleNode = this->createArticleNode(article);
      if (articleNode->isCheckArticleEmpty()) {
        return this;
      }

      if (this->articleHead == NULL) {
        this->articleHead = this->articleTail = articleNode;
      }
      else {
        articleNode->pNext = this->articleHead;
        this->articleHead = articleNode;
      }

      return this;
    }

    // Add to the end
    ArticleList *pushArticle(Article *article) {
      ArticleNode *articleNode = this->createArticleNode(article);
      if (articleNode->isCheckArticleEmpty()) {
        return this;
      }

      if (this->articleHead == NULL) {
        this->articleHead = this->articleTail = articleNode;
      }
      else {
        this->articleTail->pNext = articleNode;
        this->articleTail = this->articleTail->pNext;
      }

      return this;
    }

    // Add to the position after article
    ArticleList *addArticleAfter(Article *article, string codeArticle) {
      for (ArticleNode **node = &this->articleHead; *node != NULL; node = &(*node)->pNext) {
        if ((*node)->findArticleBy("code_article", codeArticle)) {
          if ((*node) == NULL) {
            cout << "The given previous node cannot be NULL \n";
            return this;
          }
          ArticleNode *articleNode = this->createArticleNode(article);
          if (articleNode->isCheckArticleEmpty()) {
            return this;
          }
          articleNode->pNext = (*node)->pNext;
          (*node)->pNext = articleNode;
          return this;
        }
      }

      cout << "Not found article with code_article: " << codeArticle << '\n';
      return this;
    }

    ArticleList *sortArticles(string type, string direction) {
      ArticleNode **head = &this->articleHead; 
      ArticleNode **i;

      if ((*head) == NULL) {
        cout << "Not found data\n";
        return this;
      }

      while ((*head)->pNext != NULL) {
        i = &(*head)->pNext;
        while (*i != NULL) {
          if ((*head)->compareBy(*i, type, direction)) {
            this->swapNode(&(*head)->article, &(*i)->article);
          }
          i = &(*i)->pNext;
        }
        head = &(*head)->pNext;
      }

      return this;
    }

    ArticleList *searchArticles(string type, string strMatch) {
      if (this->articleHead == NULL) {
        cout << "Not found data\n";
        return this;
      }

      ArticleList *articles = new ArticleList();
      for (ArticleNode *node = this->articleHead; node != NULL; node = node->pNext) {
        if (node->findArticleBy(type, strMatch)) {
          articles->pushArticle(node->article);
        }
      }
      this->titles.show();
      articles->getAll();

      return articles;
    }

    ArticleList *updateArticles(string strMatch, int fieldUpdate, string type = "code_article") {
      for (ArticleNode **node = &this->articleHead; *node != NULL; node = &(*node)->pNext) {
        if ((*node)->findArticleBy(type, strMatch)) {
          this->titles.show();
          (*node)->article->show();
          (*node)->article->update(fieldUpdate);
          return this;
        }
      }

      cout << "Not found article with code_article: " << strMatch;
      return this;
    }

    ArticleList *deleteArticles(string strMatch, string type = "code_article") {
      bool isFinded = false;
      while (this->articleHead != NULL && this->articleHead->findArticleBy(type, strMatch)) {
        this->articleHead = this->articleHead->pNext;
      }
      ArticleNode **prevNode = NULL;
      ArticleNode **node = &(this->articleHead->pNext);
      for (; *node != NULL; node = &(*node)->pNext) {
        if ((*node) != NULL && (*node)->findArticleBy(type, strMatch)) {
          if ((*node)->pNext == NULL) {
            (*prevNode)->pNext = NULL;
            return this;
          }
          (*prevNode)->pNext = (*node)->pNext;
          isFinded = true;
        }
        prevNode = node;
      }

      if (!isFinded) cout << "Not found article with code_article: " << strMatch << "\n";
      return this;
    }

    ArticleList *getAll() {
      if (this->articleHead == NULL) {
        cout << "Not found data\n";
        return this;
      }
      if (this->titles.created) this->titles.show();

      for (ArticleNode *node = this->articleHead; node != NULL; node = node->pNext) {
        node->article->show();
      }

      return this;
    }

    ArticleList *exportToFile(string fileName) {
      ofstream fileArticles;
      fileArticles.open(fileName, std::ofstream::out | std::ofstream::trunc);
      string content;
      for (ArticleNode *node = this->articleHead; node != NULL; node = node->pNext) {
        content += node->article->toString();
      }
      fileArticles << content;
      fileArticles.close();
      return this;
    }

  private:
    int getLengthList(ArticleNode *headNode) {
      if (headNode == NULL)
        return 0;

      return 1 + this->getLengthList(headNode->pNext);
    }

    void swapNode(Article **articleA, Article **articleB) {
      Article *articleTmp = *articleA;
      (*articleA) = (*articleB);
      (*articleB) = articleTmp;
    }
};

class MenuArticles
{
  private:
    ArticleList *articles;
    int numSelect;

  public:
    MenuArticles(ArticleList *articles) {
      this->articles = articles;
    }

    void showMainMenu() {
      cout << "++++++++++++++ Main Menu ++++++++++++++" << endl;
      cout << "1. Export data to screen" << endl;
      cout << "2. Create article" << endl;
      cout << "3. Update article by code_article" << endl;
      cout << "4. Delete article by code_article" << endl;
      cout << "5. Search article by: " << endl;
      cout << "6. Sort article by: " << endl;
      cout << "7. Export data to file" << endl;
      cout << "8. Exit" << endl;
      cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
      cout << "Enter choice of you: ";
      cin >> this->numSelect;
      this->numSelect = this->isCheckDataInput(this->numSelect);
      this->handleMainMenu();
    }

  private:
    int isCheckDataInput (int numSelected) {
      while (1) {
        if (cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "You have entered wrong input. Input must a number" << endl;
          cout << "Please Enter select again: ";
          cin >> numSelected;
        } else {
          return numSelected;
        }
      }
      return numSelected;
    }

    MenuArticles *handleMainMenu() {
      switch (this->numSelect) {
        case 1: {
          if (system("CLS")) system("clear");
          this->articles->getAll();
          break;
        }
        case 2: {
          this->showCreateMenu();
          break;
        }
        case 3: {
          this->showUpdateMenu();
          break;
        }
        case 4: {
          string strMatch;
          cout << "Enter article code: ";
          cin >> strMatch;
          this->articles->deleteArticles(strMatch)->getAll();
          break;
        }
        case 5: {
          this->showSearchMenu();
          break;
        }
        case 6: {
          this->showSortMenu();
          break;
        }
        case 7: {
          string fileNameExport;
          cout << "Please enter file name with extension txt: "; cin >> fileNameExport;
          this->articles->exportToFile(fileNameExport);
          break;
        }
        case 8: {
          if (system("CLS")) system("clear");
          return this;
        }
        default: {
          cout << "Not found your selection. Please choice again";
          break;
        }
      }

      this->showMainMenu();
      return this;
    }

    MenuArticles *showCreateMenu() {
      cout << "+++++++++++++ Create Menu +++++++++++++" << endl;
      cout << "1. Add to the head" << endl;
      cout << "2. Add to the bottom" << endl;
      cout << "3. Add to the after article" << endl;
      cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
      cout << "Enter choice of you: ";
      this->handleCreateArticles();

      return this;
    }

    MenuArticles *showSearchMenu() {
      cout << "+++++++++++++ Search Menu +++++++++++++" << endl;
      cout << "1. Search by 'Name article'" << endl;
      cout << "2. Search by 'Year publish'" << endl;
      cout << "3. Search by 'Name author'" << endl;
      cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
      cout << "Enter choice of you: ";
      this->handleSearchArticles();

      return this;
    }

    MenuArticles *showUpdateMenu() {
      cout << "+++++++++++++ Update Menu +++++++++++++" << endl;
      cout << "1. Update 'Code article'" << endl;
      cout << "2. Update 'Name article'" << endl;
      cout << "3. Update 'Name magazine'" << endl;
      cout << "4. Update 'Category magazine'" << endl;
      cout << "5. Update 'Number publish'" << endl;
      cout << "6. Update 'Episode publish'" << endl;
      cout << "7. Update 'Year publish'" << endl;
      cout << "8. Update 'Company publish'" << endl;
      cout << "9. Update 'Author'" << endl;
      cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
      cout << "Enter choice of you: ";
      this->handleUpdateArticles();

      return this;
    }

    MenuArticles *showSortMenu() {
      cout << "+++++++++++++ Search Menu +++++++++++++" << endl;
      cout << "1. Sort by 'Name article'" << endl;
      cout << "2. Sort by 'Year publish'." << endl;
      cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
      cout << "Enter choice of you: ";
      this->handleSortArticles();

      return this;
    }

    MenuArticles *handleCreateArticles() {
      cin >> this->numSelect;
      this->numSelect = this->isCheckDataInput(this->numSelect);
      Article *article = new Article();
      article->createFromScreen();

      switch (this->numSelect) {
        case 1: {
          this->articles->unshiftArticle(article)->getAll();
          break;
        }
        case 2: {
          this->articles->pushArticle(article)->getAll();
          break;
        }
        case 3: {
          string codeArticle;
          cout << "Enter article code: ";
          cin >> codeArticle;
          this->articles->addArticleAfter(article, codeArticle)->getAll();
          break;
        }
        default: {
          cout << "Not found your selection. Please choice again";
          break;
        }
      }

      return this;
    }

    MenuArticles *handleUpdateArticles() {
      string strMatch;
      int fieldUpdate;
      cin >> fieldUpdate;
      cout << "Enter article code: ";
      fieldUpdate = this->isCheckDataInput(fieldUpdate);
      cin >> strMatch;
      cout << "Enter field need update: ";
      this->articles->updateArticles(strMatch, fieldUpdate)->getAll();
      return this;
    }

    MenuArticles *handleSearchArticles() {
      cin >> this->numSelect;
      this->numSelect = this->isCheckDataInput(this->numSelect);
      string type = "name_article";
      string strMatch;
      cout << "Enter keywords search:";
      cin >> strMatch;
      switch (this->numSelect) {
        case 1: {
          type = "name_article";
          break;
        }
        case 2: {
          type = "year_publish";
          break;
        }
        case 3: {
          type = "author";
          break;
        }
        default: {
          cout << "Number not valid";
          return this->showSearchMenu();
         }
      }
      this->articles->searchArticles(type, strMatch);
      return this;
    }

    MenuArticles *handleSortArticles() {
      cin >> this->numSelect;
      this->numSelect = this->isCheckDataInput(this->numSelect);

      int direction = 1;
      cout << "1. Sort up ascending\n";
      cout << "2. Sort descending\n";
      cin >> direction;
      direction = this->isCheckDataInput(direction);

      string type = "name_article";
      string directionStr = "asc";

      if (this->numSelect == 2)
        type = "year_publish";
      if (direction == 2)
        directionStr = "desc";

      this->articles->sortArticles(type, directionStr)->getAll();
      return this;
    }
};

int main() {
  string articleFileName = "./data_article.txt";
  ArticleList *articles = new ArticleList(articleFileName);
  MenuArticles *menu = new MenuArticles(articles);

  cout << "Topic 17: Management of scientific articles using linked list. \n";
  menu->showMainMenu();
  return 0;
}
