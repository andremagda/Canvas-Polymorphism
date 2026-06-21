// A4 test driver program
#include <iostream>
#include "Canvas.h"
#include "Rectangle.h"
#include "Isosceles.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include "LL_Parallelogram.h"
#include "RL_Parallelogram.h"

using std::cout;

//Function prototypes
void test_Canvas();
void test_Shapes();
void test_Polymorphism();
void test_draw_house();

int main() {
   test_Canvas();
   test_Shapes();
   test_Polymorphism();
   test_draw_house();
  return 0;
}

void test_Canvas() {
   Canvas can{10, 4, '.'};
   std::cout << "(a)\n" << can << '\n';

   can.fill(':');
   std::cout << "(b)\n" << can << '\n';

   can.clear();
   std::cout << "(c)\n" << can << '\n';

   can.write_horizontal(3, 1, "ABC");
   std::cout << "(d)\n" << can << '\n';

   can.write_horizontal(5, 2, "X");
   std::cout << "(e)\n" << can << '\n';

   can.write_horizontal(6, 3, "Y");
   std::cout << "(f)\n" << can << '\n';

   can.write_horizontal(7, 4, "Z");
   std::cout << "(g)\n" << can << '\n';

   can.write_vertical(9, 1, "nice");
   std::cout << "(h)\n" << can << '\n';

   can.rotate();
   std::cout << "(i)\n" << can << '\n';
   can.rotate();
   std::cout << "(j)\n" << can << '\n';
   can.rotate();
   std::cout << "(k)\n" << can << '\n';
   can.rotate();
   std::cout << "(l)\n" << can << '\n';

   Canvas screen{15, 15};
   std::cout << "(m)\n" << screen << '\n';

   screen.overlay(can, 3, 2);
   std::cout << "(n)\n" << screen << '\n';

   can.rotate();
   std::cout << "(o)\n" << can << '\n';

   screen.overlay(can, 4, 5);
   std::cout << "(p)\n" << screen << '\n';

   screen.setCornerFrame('o');
   screen.setHorizontalFrame('~');
   screen.setVerticalFrame('^');
   screen.write_vertical(14, 1, "That's all folks");

   screen.put('#', 6, 6);

   std::cout << "(q)\n" << screen << '\n';
 }

 void test_Shapes() {
   Rectangle rect{7, 5};
   cout << rect.toString() << '\n';
   //cout << rect << '\n';

   Rhombus ace{16, "Ace of diamond"};
   cout << ace << '\n';

   Isosceles iso{17};
   cout << iso << '\n';

   RightTriangle rt{10, "Carpenter's square"};
   cout << rt << '\n';

   LL_Parallelogram llp{7, 5};
   cout << llp.toString() << '\n';

   RL_Parallelogram rlp{7, 5};
   cout << rlp.toString() << '\n';

   Canvas rectCan{rect.draw()}; //same as Canvas aceCan (rect.draw());
   cout << rectCan << '\n';

   Canvas aceCan{ace.draw('V')};  // same as Canvas aceCan = ace.draw();
   cout << aceCan << '\n';

   Canvas isoCan{iso.draw('^')};
   cout << isoCan << '\n';

   isoCan = iso.draw('V');
   cout << isoCan << '\n';

   Canvas rtCan{rt.draw('L')};
   cout << rtCan << '\n';

   Canvas llpCan{llp.draw('\\')};
   cout << llpCan << '\n';

   Canvas rlpCan{rlp.draw('/')};
   cout << rlpCan << '\n';

   rlpCan.setCornerFrame(' ');
   rlpCan.setHorizontalFrame(' ');
   rlpCan.setVerticalFrame(' ');
   cout << rlpCan << '\n';
}

void test_Polymorphism() 
{
   // create a vector of smart pointers to Shape
   std::vector<std::unique_ptr<Shape>> shapeVec;

   // Next, add some shapes to shapeVec
   shapeVec.push_back(std::make_unique<Rectangle>(7, 5));
   shapeVec.push_back(std::make_unique<Rhombus>(16, "Ace"));
   shapeVec.push_back(std::make_unique<Isosceles>(17));
   shapeVec.push_back(std::make_unique<RightTriangle>(10, "Framing square"));
   shapeVec.push_back(std::make_unique<LL_Parallelogram>(7, 5, "Left slanted Box"));
   shapeVec.push_back(std::make_unique<RL_Parallelogram>(7, 5, "Right slanted Box"));

   // now, draw the shapes polymorfically
   for (const auto& shpPtr : shapeVec) 
   {
     cout << shpPtr->draw() << '\n';  // Polymorphic call because
                                      // 1) shpPtr is a pointer to Shape
                                      // 2) the draw() method in Shape is virtual
     cout << shpPtr->toString();      // Also a polymorphic call
     cout << '\n';
   }
}

using std::cout;

// Draws shp on can at pairs of coordinates using pen
void do_polymorphic_draw(Canvas& can, Shape& shp,
             std::vector<std::pair<int, int>> vec, char pen = '*') { 
   for (const auto& p : vec)
   {
      can.overlay(shp.draw(pen), p.first, p.second);
   }
}

void test_draw_house() {
  Canvas can{65, 25};
  // std::cout << "can:\n" << can << "\n===================\n";

  Rectangle rect_1_11{1, 11, "vertical 1 by 11"};
  do_polymorphic_draw(can, rect_1_11, {{13, 8}},'\\'); // left wall side
  do_polymorphic_draw(can, rect_1_11, {{62, 8}}, '/'); // right wall side
  do_polymorphic_draw(can, rect_1_11, {{61, 8}, {14, 8}, {58, 9}}, '|'); // both wall sides

  Rectangle rect_2_10{2, 10, "vertical 2 by 10"};
  do_polymorphic_draw(can, rect_2_10, {{15, 9}, {45, 9}, {59, 9}, {30, 9}}, '='); // the == columns

  Rectangle rect_1_5{1, 5, "vertical 1 by 5"};
  do_polymorphic_draw(can, rect_1_5,
          {{18, 11}, {23, 11}, {28, 11}, {33, 11}, {38, 11}, {43, 11}}, '|'); // house window side bars

  Rectangle rect_1_3{1, 3, "vertical 1 by 3"};
  do_polymorphic_draw(can, rect_1_3,
          {{15, 3}, {23, 3}, {24, 3}, {28, 3}, {32, 3}, {36, 3}, {37, 3}}, '|'); // roof winndow side bars

   do_polymorphic_draw(can, rect_1_3, {{55, 14}}, ':');

  Rectangle rect_1_8{1, 8, "vertical 1 by 8"};
   do_polymorphic_draw(can, rect_1_8, {{47, 11}, {48, 11}, {56, 11}}, '|'); // other side bars

  Rectangle rect_4_1{4, 1, "horizontal 4 by 1"};
   do_polymorphic_draw(can, rect_4_1, {{19, 11}, {24, 11}, {34, 11}, {39, 11}}, ':');  // house windows
   do_polymorphic_draw(can, rect_4_1, {{19, 12}, {24, 12}, {34, 12}, {39, 12}}, ':'); // house windows

  //"horizontal ----"
  do_polymorphic_draw(can, rect_4_1, {{19, 13}, {24, 13}, {34, 13}, {39, 13}}, '_');

  //"horizontal ^^^^"
  do_polymorphic_draw(can, rect_4_1, {{19, 14}, {24, 14}, {34, 14}, {39, 14}}, '^');

  //"horizontal ____"
  do_polymorphic_draw(can, rect_4_1, {{19, 10}, {24, 10}, {34, 10}, {39, 10}}, '_');

  //"horizontal ____"
  do_polymorphic_draw(can, rect_4_1, {{19, 15}, {24, 15}, {34, 15}, {39, 15}}, '_');

 //"horizontal UUUUUUUUUUUUU"
  Rectangle rect_13_1(13, 1, "horizontal 13 by 1");
  do_polymorphic_draw(can, rect_13_1, {{23, 7}}, 'U'); // roof

  do_polymorphic_draw(can, rect_13_1, {{24, 1}, {23, 2}}, '_'); // above roof window

  do_polymorphic_draw(can, rect_13_1, {{24, 6}}, '=');         // bottom of roof window

  do_polymorphic_draw(can, rect_13_1, {{45, 22}}, '"');       // house bottom left corner

  Rectangle rect_7_1{7, 1, "rect_3_1"};
  do_polymorphic_draw(can, rect_7_1, {{49, 18}, {48, 19}, {48, 21}, {49, 11}}, '_'); // horizontal window bars

  Rectangle rect_9_1{9, 1, "rect_3_1"};
  can.overlay(rect_9_1.draw('"'), 47, 20); // front of door

  Rectangle rect_3_1{3, 1, "rect_3_1"};
  do_polymorphic_draw(can, rect_3_1, {{25, 3}, {29, 3}, {33, 3}, {25, 4}, {29, 4}, {33, 4}}, '.'); // the 3 dots ... on windows

  do_polymorphic_draw(can, rect_3_1, {{25, 5}, {29, 5}, {33, 5}}, '^'); // ^^^ on windows

  Rectangle rect_15_1(15, 1, "rect_15_1");
  can.overlay(rect_15_1.draw('U'), 23, 7); // horizontal UUUUUUUUUUUUUUU

  Rectangle rect_45_1(45, 1, "rect 45 by 1");
  can.overlay(rect_45_1.draw('"'), 15, 8); // roof front edge double quotation marks

  Rhombus rhom_3(3, "rhom_3");
  do_polymorphic_draw(can, rhom_3, {{51, 12}, {51, 15}}); // two small rhombuses on door

  LL_Parallelogram llp_19_5{19, 5, "left slanted 19 by 5"};
  can.overlay(llp_19_5.draw('U'), 38, 3); // roof, right end
  
  LL_Parallelogram llp_1_5{1, 5, "left slanted 1 by 5"};
  do_polymorphic_draw(can, llp_1_5, {{57, 3}, {56, 19}, {61, 19}}, '\\'); // roof edge, door way

  RL_Parallelogram rlp_4_5{4, 5, "right slanted 4 b 5"};
  can.overlay(rlp_4_5.draw('U'), 15, 3); // roof, left end

  RL_Parallelogram rlp_1_5{1, 5, "right slanted 1 by 5"};
  do_polymorphic_draw(can, rlp_1_5, {{14, 3}, {44, 19}, {9,19}}, '/'); // roof edge, door way

  RightTriangle rt(4, "RT 4 by 4");
  Canvas rtCan{rt.draw('U')}; // roof, right side
  can.overlay(rtCan, 38, 4);
  rtCan.rotate();
  rtCan.rotate();
  rtCan.rotate();
  can.overlay(rtCan, 19, 4); // roof, left side

  Rectangle rect_3_2{3, 1, "rect 3 by 2"}; //******* */
  Isosceles iso_9(9, "iso 9");
  Isosceles iso_7(7, "iso 7");
  Isosceles iso_5(5, "iso 5");
  can.overlay(rect_3_2.draw('|'), 6, 25); // tree trunk
  can.overlay(iso_9.draw('*'), 3, 20);    // bottom tree
  can.overlay(iso_7.draw('*'), 4, 18);    // middle tree
  can.overlay(iso_5.draw('*'), 5, 16);    // top tree

  can.write_horizontal(18, 16, "''' == = =  == == =   ===");
  can.write_horizontal(18, 17, "''\"\"\"\"\"o&,@%8ow8@&w8@&\"\"\"");
  can.write_horizontal(18, 18, "\"\"\"\"=.o%&hjw8@&o.== == ==");
  can.write_horizontal(13, 19, "\\|\"'''''=o&,@%8ow8@ = == == ");
  can.write_horizontal(13, 19, "\"\"\"\"\"\"\"\"\"|_____________|\"\"\"\"");
  can.write_horizontal(15, 2, "|==|");
  can.write_horizontal(15, 1, "____");
  can.write_horizontal(23, 2, "/");
  can.write_horizontal(37, 2, "\\");
  can.write_horizontal(48, 11, ".");
  can.write_horizontal(56, 11, ".");

  can.write_horizontal(50, 10, "5421");
  can.write_horizontal(18, 9, "= == === =");
  can.write_horizontal(33, 9, "= == == === == == = ====");
  can.write_horizontal(55, 15,"O");
  can.write_horizontal(10, 20,
                         "   ^ \" '  ''  ^~^   ~^~   ^\" ^ ~^~~");
   can.write_horizontal(14, 21, "~^~^\" ^\" ^ ~^^\"   ~^~    ^~^~");
   can.write_horizontal(14, 22, "   ~^~~^~''\"^  ~^~~^~'\"'");
   can.write_horizontal(14, 23, "\" ^\" ^ ~^^\"   ~^~    ^~^~");

   //can.write_horizontal(, , "");
   can.write_horizontal(59, 20, "~^^\"' '");
   can.write_horizontal(60, 21, "''^~^~");
   can.write_horizontal(61, 22, "^ ~^ ");
   can.write_horizontal(37, 19, "~^~~(())");
   can.write_horizontal(35, 20, "~(()(()");  

    std::cout << can << "\n\n";

}
