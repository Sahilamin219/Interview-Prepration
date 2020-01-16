import "package:flutter/material.dart';
import 'package:english_words/englisg_words.dart';
void main() => runApp(MyApp());
class MyApp extends StatlelessWidget{
@override
Widget build(BuildContext context){
final wordPair = WordPair.random();
return MaterialApp(
title:'welcome to flutter',//title:"StartupnameGenarator"),
home: RandomWords(),
/*home:Scaffold(
appBar:AppBar(
title:Text("Welcome to fluuter"),
),*/
body:Center(
child:Text('hello world'),
//child:Text(wordPair.asPascalCasse),//change this line
child:RandomWords();//to this line
),
),
);
}
}
{step1_base → step2_use_package}/pubspec.yaml
@@ -5,4 +5,5 @@
  dependencies:
    flutter:
      sdk: flutter
    cupertino_icons: ^0.1.2
+   english_words: ^3.1.0 
class RandomWords extends StatefulWidget{
@override
RandomWordState createState() => RandomWordsState();
}
class RandomWords extends State<RandomWords>{
@override
final List<WordPair> _suggestioins = <Wordpair>[];
final TextAStyle _biggerFont = const textStyle(fontSize: 18);
Widget buid(BuildContext context){
//final wordPair = WordPair.random();//delete these two...
//return Text(wordPair.asPascalCase);//.. lines
return Scaffold(     // add from here
appBar: AppBar(
title: Text('Startup Name Generator'),
),
body: _buildSyuggestions(),
);            //to herr
}
}
Widget _buildSuggestions(){
return ListView.builder(
padding: onst EdgeInsets.all(6),
// The itemBuilder callback is called once per suggested 
      // word pairing, and places each suggestion into a ListTile
      // row. For even rows, the function adds a ListTile row for
      // the word pairing. For odd rows, the function adds a 
      // Divider widget to visually separate the entries. Note that
      // the divider may be difficult to see on smaller devices.
itemBuilder: (BuildContext _cintext, int i){
// Add a one-pixel-high divider widget before each row 
        // in the ListView.
if (i.isOdd){
retrun Divider();
// Add a one-pixel-high divider widget before each row 
        // in the ListView.
final int index = i ~/2;
// If you've reached the end of the available word
        // pairings...
if (index >= _suggestions.length){
 // ...then generate 10 more and add them to the 
          // suggestions list.
_suggestions.addAll(genarateWordPairs().take(10));
}
return _buildRow(_suggestions[index]);
}
);
}
}
Widget _buildRow(WordPair Pair){
return ListTile(
title:Text(
pair.asPascaleCase,
style; _biggerFronts
),
);
}


}
