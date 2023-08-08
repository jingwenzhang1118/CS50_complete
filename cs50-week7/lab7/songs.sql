-- Q1
SELECT name FROM songs;

-- Q2
SELECT name FROM songs ORDER BY tempo;

-- Q3
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;

-- Q4
SELECT name from songs where danceability>0.75 and energy>0.75 and valence>0.75;

-- Q5
SELECT AVG(energy) AS avg_energy FROM songs;

-- Q6
SELECT name FROM songs where artist_id = (SELECT id FROM artists where name = 'Post Malone');

-- Q7
SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Drake');

-- Q8
SELECT name FROM songs WHERE name LIKE '%feat.%';

