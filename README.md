## This is a program for compare the similarity of texts.

### Enviroment: 
	- Linux Debian / Ubuntu

### Requirements: 
	- g++ compiler

### How to run it:

- $ g++ project.cpp -o project
- $ ./project

### Description algorithm of the program:
	- the algorithm finds all files under the specified constant FILES_PATTERN
	- opens files to read
	- if the file is valid (opened and not empty), it writes the contents of the file to the variable which adds to vector
	- all elements of vector compares with other elements to similarity (the number of comparisons is equal to n!/((n-2)!*2!), where n - amount of texts). Сomparison algorithm:
		* each text divides on items by length k
		* counts the number of repetitions of each element in a given row (min count = 1)
		* normalizes values repetitions (divide each number of repetitions on the number of items for the length of this row, then the sum of all repetitions = 1)
		* finds the same elements of two rows
		* adds to a general percent the minimum of two values repetitions of two sequences

### Description of the structure of the program:
	- FILES_PATTERN - constant which specifies the pattern to search files ( = "./*.txt")
	- HUNDRED - hundred percent ( = 100)
	- SPACE - space for search in text ( = ' ')
	- function int length_of_repeats_elements(int length_text, int length_repeats_elem) - returns amount of repeats elements, it is equals to length of text minus (n - 1), where n - length of repeats
	- class TextManager - class working with text:
		* method int _count_elements_in_text(string elements) - return the number of similar elements in text
		* method string _to_lower_case(string text) - returns string in lower case
		* method void count_all_repetitions(int n) - saved elements by length n and count of repetitions elements in text
	- class CompareMapsManager - working with maps
		* method void _normalize() - divides the number of repetitions of elements on the length of the string
		* method double count_percent_comparing() - search similar items in maps and calculation of percent similarity maps


### Example start:
# ---
$ ./project 
Reading file: ./example_1.txt
--> text of file: Nullam gravida mattis feugiat. In imperdiet malesuada ornare. Donec vitae laoreet diam. Praesent nec velit facilisis, viverra sem ac, finibus eros. Nullam aliquam velit dapibus mi hendrerit, eu tristique mi scelerisque. Curabitur in felis est. Ut ante risus, placerat eget nisl quis, posuere aliquet urna. Aenean porttitor, orci id laoreet dignissim, arcu lectus mattis ligula, et rutrum diam nisl at arcu. Integer suscipit volutpat tortor, ut imperdiet dui viverra quis. Fusce nec orci convallis, pulvinar nunc placerat, venenatis sapien. Nam non accumsan augue. Duis eu nunc ex. Proin lobortis lorem eget mi suscipit mattis.

----------------------------------
Reading file: ./example_2.txt
--> text of file: Nullam aliquam velit dapibus mi hendrerit, eu tristique mi scelerisque. Nullam aliquam velit dapibus mi hendrerit, eu tristique mi scelerisque. Curabitur in felis est. Ut ante risus, placerat eget nisl quis, posuere aliquet urna. Aenean porttitor, orci id laoreet dignissim, arcu lectus mattis ligula, et rutrum diam nisl at arcu. Integer suscipit volutpat tortor, ut imperdiet dui viverra quis. Fusce nec orci convallis, pulvinar nunc placerat, venenatis sapien. Sed lobortis pulvinar ornare. Donec at mi gravida, mattis eros in, tempor nibh. Phasellus euismod vitae metus nec pellentesque. Praesent eget diam at eros elementum viverra. Donec eget elit nisi. Donec non sapien ut enim malesuada vulputate.

----------------------------------
Reading file: ./example_3.txt
--> text of file: Nullam gravida mattis feugiat. In imperdiet malesuada ornare. Donec vitae laoreet diam. Praesent nec velit facilisis, viverra sem ac, finibus eros. Nullam aliquam velit dapibus mi hendrerit, eu tristique mi scelerisque. Curabitur in felis est. Ut ante risus, placerat eget nisl quis, posuere aliquet urna. Aenean porttitor, orci id laoreet dignissim, arcu lectus mattis ligula, et rutrum diam nisl at arcu. Integer suscipit volutpat tortor, ut imperdiet dui viverra quis. Fusce nec orci convallis, pulvinar nunc placerat, venenatis sapien. Nam non accumsan augue.Duis eu nunc ex. Proin lobortis lorem eget mi suscipit mattis.Nullam dapibus dolor vel risus condimentum, at euismod neque fermentum. Vivamus ante est, faucibus vitae porta vel, sodales sed tortor. Vestibulum venenatis nec risus vel volutpat. Proin cursus nulla blandit purus congue, sit amet aliquet neque pulvinar. Cras tempus est at ultricies pharetra. Nam a rhoncus ex, id mattis leo. Proin dapibus ultrices quam, ut cursus urna luctus nec. Nunc ultricies tortor in tempor iaculis. Pellentesque consectetur pellentesque diam sit amet mattis.

----------------------------------
Reading file: ./example_4.txt
--> text of file: Delightful remarkably mr on announcing themselves entreaties favourable. About to in so terms voice at. Equal an would is found seems of. The particular friendship one sufficient terminated frequently themselves. It more shed went up is roof if loud case. Delay music in lived noise an. Beyond genius really enough passed is up. Was justice improve age article between. No projection as up preference reasonably delightful celebrated. Preserved and abilities assurance tolerably breakfast use saw. And painted letters forming far village elderly compact. Her rest west each spot his and you knew. Estate gay wooded depart six far her. Of we be have it lose gate bred. Do separate removing or expenses in. Had covered but evident chapter matters anxious. Article evident arrived express highest men did boy. Mistress sensible entirely am so. Quick can manor smart money hopes worth too. Comfort produce husband boy her had hearing. Law others theirs passed but wishes. You day real less till dear read. Considered use dispatched melancholy sympathize discretion led. Oh feel if up to till like. Attention he extremity unwilling on otherwise. Conviction up partiality as delightful is discovered. Yet jennings resolved disposed exertion you off. Left did fond drew fat head poor. So if he into shot half many long. China fully him every fat was world grave. In friendship diminution instrument so. Son sure paid door with say them. Two among sir sorry men court. Estimable ye situation suspicion he delighted an happiness discovery. Fact are size cold why had part. If believing or sweetness otherwise in we forfeited. Tolerably an unwilling arranging of determine. Beyond rather sooner so if up wishes or. And produce say the ten moments parties. Simple innate summer fat appear basket his desire joy. Outward clothes promise at gravity do excited. Sufficient particular impossible by reasonable oh expression is. Yet preference connection unpleasant yet melancholy but end appearance. And excellence partiality estimating terminated day everything. Meant balls it if up doubt small purse. Required his you put the outlived answered position. An pleasure exertion if believed provided to. All led out world these music while asked. Paid mind even sons does he door no. Attended overcame repeated it is perceive marianne in. In am think on style child of. Servants moreover in sensible he it ye possible. She suspicion dejection saw instantly. Well deny may real one told yet saw hard dear. Bed chief house rapid right the. Set noisy one state tears which. No girl oh part must fact high my he. Simplicity in excellence melancholy as remarkably discovered. Own partiality motionless was old excellence she inquietude contrasted. Sister giving so wicket cousin of an he rather marked. Of on game part body rich. Adapted mr savings venture it or comfort affixed friends. Unpacked now declared put you confined daughter improved. Celebrated imprudence few interested especially reasonable off one. Wonder bed elinor family secure met. It want gave west into high no in. Depend repair met before man admire see and. An he observe be it covered delight hastily message. Margaret no ladyship endeavor ye to settling. Expenses as material breeding insisted building to in. Continual so distrusts pronounce by unwilling listening. Thing do taste on we manor. Him had wound use found hoped. Of distrusts immediate enjoyment curiosity do. Marianne numerous saw thoughts the humoured. 

----------------------------------
Reading file: ./example_5.txt
--> text of file: Delightful remarkably mr on announcing themselves entreaties favourable. About to in so terms voice at. Equal an would is found seems of. Was justice improve age article between. No projection as up preference reasonably delightful celebrated. Preserved and abilities assurance tolerably breakfast use saw. And painted letters forming far village elderly compact. Her rest west each spot his and you knew. Article evident arrived express highest men did boy. Mistress sensible entirely am so. Quick can manor smart money hopes worth too. Comfort produce husband boy her had hearing. Law others theirs passed but wishes. You day real less till dear read. Attention he extremity unwilling on otherwise. Conviction up partiality as delightful is discovered. Yet jennings resolved disposed exertion you off. Left did fond drew fat head poor. So if he into shot half many long. China fully him every fat was world grave. And produce say the ten moments parties. Simple innate summer fat appear basket his desire joy. Outward clothes promise at gravity do excited. Sufficient particular impossible by reasonable oh expression is. Yet preference connection unpleasant yet melancholy but end appearance. And excellence partiality estimating terminated day everything. Meant balls it if up doubt small purse. Required his you put the outlived answered position. An pleasure exertion if believed provided to. All led out world these music while asked. Paid mind even sons does he door no. Attended overcame repeated it is perceive marianne in. In am think on style child of. Servants moreover in sensible he it ye possible. Unpacked now declared put you confined daughter improved. Celebrated imprudence few interested especially reasonable off one. Wonder bed elinor family secure met. It want gave west into high no in. Depend repair met before man admire see and. Expenses as material breeding insisted building to in. Continual so distrusts pronounce by unwilling listening. Thing do taste on we manor. 

----------------------------------
Reading file: ./example_empy.txt
File ./example_empy.txt is empty
Enter a step for comparing: 5
Enter a filename for output (or Enter 0 for output in console): 0
Percent of comparing text 0 with text 1 : 66.3047
Percent of comparing text 0 with text 2 : 61.1975
Percent of comparing text 0 with text 3 : 0.374856
Percent of comparing text 0 with text 4 : 0.451581
Percent of comparing text 1 with text 2 : 49.3516
Percent of comparing text 1 with text 3 : 0.432526
Percent of comparing text 1 with text 4 : 0.501756
Percent of comparing text 2 with text 3 : 0.605536
Percent of comparing text 2 with text 4 : 0.592336
Percent of comparing text 3 with text 4 : 62.9527

### Link to the repository: https://github.com/Sashkiv/comparing_texts
