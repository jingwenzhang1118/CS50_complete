UPDATE shows SET title = "How I Met Your Mother" WHERE title = "How i met your mother";
SELECT * FROM shows ORDER BY title;

SELECT * FROM shows
 WHERE lower(title) = 'arrow';
UPDATE shows SET title = "Arrow" WHERE title = "arrow";

SELECT * FROM shows
 WHERE lower(title) LIKE 'adventure%';
UPDATE shows SET title = "Adventure Time" WHERE title = "adventure time";

SELECT * FROM shows
 WHERE lower(title) LIKE 'avatar%';
UPDATE shows SET title = "Avatar: The Last Airbender" WHERE lower(title) LIKE 'avatar%';

SELECT * FROM shows
 WHERE lower(title) LIKE 'brooklyn%';
SELECT * FROM shows
 WHERE lower(title) LIKE '%99%';
UPDATE shows SET title = "Brooklyn Nine-Nine" WHERE lower(title) LIKE '%99';

SELECT * FROM shows
 WHERE lower(title) LIKE 'community';
UPDATE shows SET title = 'Community' WHERE lower(title) = 'community';

SELECT * FROM shows
 WHERE lower(title) LIKE 'family%';
UPDATE shows SET title = "Family Guy" WHERE lower(title) LIKE 'family%';

SELECT * FROM shows
 WHERE lower(title) LIKE 'friends';
UPDATE shows SET title = "Friends" WHERE lower(title) LIKE 'friends';

SELECT * FROM shows
 WHERE lower(title) LIKE 'game%';

SELECT * FROM shows
 WHERE lower(title) LIKE 'gilmore%';
UPDATE shows SET title = "Gilmore Girls" WHERE lower(title) LIKE 'gilmore%';

SELECT * FROM shows
 WHERE lower(title) LIKE 'grey%';
UPDATE shows SET title = "Grey's Anatomy" WHERE lower(title) LIKE 'grey%';

SELECT * FROM shows
 WHERE lower(title) LIKE 'how%mother';

SELECT * FROM shows
 WHERE lower(title) LIKE '%philadelphia';

SELECT * FROM shows
 WHERE lower(title) LIKE '%always sunny%';
UPDATE shows SET title = "It's Always Sunny in Philidelphia" WHERE lower(title) LIKE '%always sunny%';

SELECT * FROM shows
 WHERE lower(title) LIKE 'park%';
UPDATE shows SET title = "Parks and Recreation" WHERE lower(title) LIKE 'park%';


SELECT * FROM shows
 WHERE lower(title) LIKE 'sherlock%';
UPDATE shows SET title = "Sherlock" WHERE lower(title) LIKE 'sherlock%';

SELECT * FROM shows
 WHERE lower(title) LIKE 'squid%';
UPDATE shows SET title = "Squid Game" WHERE lower(title) LIKE 'squid%';

SELECT * FROM shows
 WHERE lower(title) LIKE '%bachelo%';
UPDATE shows SET title = "The Bachelorette" WHERE lower(title) LIKE '%bachelo%';

SELECT * FROM shows
 WHERE lower(title) LIKE '%crown';
UPDATE shows SET title = "The Crown" WHERE lower(title) LIKE '%crown';

SELECT * FROM shows
 WHERE lower(title) LIKE '%office';
UPDATE shows SET title = "The Office" WHERE lower(title) LIKE '%office';

SELECT * FROM shows
 WHERE lower(title) LIKE '%gambit';
UPDATE shows SET title = "The Queen's Gambit" WHERE lower(title) LIKE '%gambit';

SELECT * FROM shows
 WHERE lower(title) LIKE '%untam%';
UPDATE shows SET title = "The Untamed" WHERE lower(title) LIKE '%untam%';


UPDATE shows SET title = "Billions" WHERE lower(title) = 'billions';
UPDATE shows SET title = "Criminal Minds" WHERE lower(title) = 'criminal minds';
UPDATE shows SET title = "Game of Thrones" WHERE lower(title) = 'GoT';

SELECT * FROM shows ORDER BY title;