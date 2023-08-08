DROP TABLE students;

CREATE TABLE students (
    id INTEGER,
    student_name TEXT,
    house_id INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY (house_id) REFERENCES house(house_id)
);

CREATE TABLE house (
    house_id INTEGER,
    house_name TEXT,
    head_id INTEGER,
    PRIMARY KEY (house_id),
    FOREIGN KEY (head_id) REFERENCES head(head_id)
);

CREATE TABLE head (
    head_id INTEGER,
    head_name TEXT,
    PRIMARY KEY (head_id)
);
