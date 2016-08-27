
======================================== Description of modifications ==================================================

1. Renamed mysearch.module.php to mysearch.module.
2. Created mysearch.info file.
3. Modifications in function mysearch_menu(). Changed “$items['mysearch']“ to the “$items['mysearch/%']“
   and “$items['mysearch/%/%’]“. Added “'page arguments' => array(1, 2),”.
   Added a menu item for a second opportunity to limit the number of displayed items.
4. Added title arguments', 'title callback' for the dynamic formation of the title.
5. Changing the function mysearch_searchpage ($ searchterm, $ count), which queries the database and generates a data array.
   Additionally added to the body field a request for the implementation of the text display with backlight term search
   mysearch_body_lighting_trimming ($ search, $ term).
6. Is displayed on the screen via a standard feature theming theme_item_list ()
   function included in mysearch_output ($ items, $ attributes).

========================================== Additional functionality ====================================================

7. Creating a block with the search form where you can specify the Number of items displayed on the search page
   (When you install the module without changing the unit configuration 7 elements).
   To do this, the files are created in addition mysearch.install and block.inc.


================================================== Using ===============================================================

8.  1. Enable module.
    2. On the blocks administration page to configure the unit simple search form
    3. Use))