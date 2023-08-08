
-- Q1
SELECT title FROM movies WHERE year = '2008';

-- Q2
SELECT birth FROM people WHERE name = 'Emma Stone';

-- Q3
SELECT title FROM movies WHERE year >= 2018 ORDER BY title;


-- Q4
SELECT count(*) FROM movies WHERE id in (SELECT movie_id FROM ratings WHERE rating = 10.0);

-- Q5
SELECT title, year FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year;

-- Q6
SELECT AVG(rating) FROM ratings WHERE movie_id in (SELECT id FROM movies WHERE year = 2012);

-- Q7
SELECT title, rating -- there is no need to specify table, or movies.title
    FROM movies JOIN ratings ON movies.id = ratings.movie_id
    WHERE year = 2010 and rating > 0
ORDER BY rating DESC, title ASC;

-- Q8
SELECT name FROM people
 WHERE id in (SELECT person_id FROM stars
               WHERE movie_id = (SELECT id FROM movies WHERE title = 'Toy Story'));

-- Q9
SELECT name FROM people
 WHERE id in (SELECT person_id FROM stars
               WHERE movie_id in (SELECT id FROM movies WHERE year = 2004))
            ORDER BY birth;

-- Q10
SELECT name FROM people
 WHERE id in (SELECT person_id FROM directors
               WHERE movie_id in (SELECT movie_id FROM ratings WHERE rating >= 9.0));

-- Q11
SELECT title FROM movies
 JOIN ratings ON movies.id = ratings.movie_id
 WHERE id in (SELECT movie_id FROM stars
               WHERE person_id = (SELECT id FROM people
                                   WHERE name = 'Chadwick Boseman'))
ORDER BY rating DESC LIMIT 5;


-- Q12
SELECT title FROM movies
 WHERE id in (SELECT movie_id FROM stars
               WHERE stars.person_id = (SELECT id FROM people WHERE name = 'Helena Bonham Carter')
                                           AND movie_id in (SELECT movie_id FROM stars
                                                             WHERE stars.person_id = (SELECT id FROM people WHERE name = 'Johnny Depp')));




-- Q13
SELECT name FROM people
 WHERE id IN (SELECT person_id FROM stars
                      WHERE movie_id IN (SELECT movie_id FROM stars
                                          WHERE person_id = (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958)))
   And name != 'Kevin Bacon' AND birth != 1958;