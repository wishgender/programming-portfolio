# Notes To Self While Working on Project 4
## Saturday, Nov. 23rd, 2024
### debug cout stmts
* 2:52 P.M. `AST::mainHeader...while((*obj)->tag)!="function")`
* 3:10 P.M. jesus I should really have just used markdown or a txt file //this is when i was using TeX//
* 3:38 P.M. two `for` loops inside `AST::mainHeader` to print out name of `profile` and `file`
* ???? P.M. `std::cout << includeProfile << std::endl;` (inside the for loop making the header to print)
* 5:24 P.M. finally made a markdown version of this so i won't lose my mind lol

### code i removed from mainReport
    std::list<AST*>::iterator blockEnd;
    while((*obj)->tag != "function") {
    (*obj)->print(std::cout);                  //TEST CODE
        ++obj;
    std::cout << j++ << std::endl;
    }
    while(!(*obj)->getChild("main")) {
        ++obj;
        std::cout << j + 100;
    }
        blockEnd = (getChild("main"))->child.end();
    --blockEnd;

    while((*blockEnd)->tag != "return") {
        --blockEnd;
    }
    --blockEnd;

    
    child.insert(blockEnd, new AST(token, printReport));`

### other notes
So i just did that thing where i almost piss myself again smh
luckily i did not piss myself 

<html><em style="color: yellow">go piss girl</em></html>

## Monday, Dec. 2nd, 2024
### Initial notes
<b>8:11 A.M.</b><br>
ok so today I need to start working on milestone 3. I got my grade back for milestone 2, which is a 98 (apparently I left some code commented again) but that's not a big deal, thankfully. Still haven't gotten my regrade for m1, but I really hope I properly committed my `simple.cpp` file because that would be devastating lol

#### anyway the main goals for m3 are:
* `functionCount()`
* `lineCount()`

