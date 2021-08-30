# Digit Classification

* First we will import the data that is the digits
* There are 10 folders with around 1000 images of each digit
* Then we will keep all this images in the single list and create a corresponding list which contains all the labels of the images 
* Then we will split the data into three parts

** Training
** Testing
** Validation

***

#### Training Set

* This is the traditional data set which is used for training the model in machine learning or deep learing
* Training data set is more like a practice problem that students use to practice at home for the test


#### Validation Set

* Generally validation data set is used interchangebly with the test set
* It refers to the sample data held back from training the model
* We can't evaluate the model on the trained data set as it can result in the biased score
* Model should be evaluated on samples that were not used to build or fine tune the model
* Validation set is used to validate our model during training, these help us in adjusting the hyper parameters
* That is in each epoch it is trained on the training set and also validated on the validation set

#### Test Set

* Test set in the set of data that is used to test the model after it is completed the training
* Test set is separate from both Training and Validation set

***

* Then we will plot the training images distribution, so that we can see data of each class is distributed equally or not

*** 

## What to do if distribution is not equally spreaded?
## One Hot Encoding
## Different Encodings
## Need to check the answer
## Optimizers like adam 
## L1, L2 regressions
## Different types of normalizations 
## Different activation functions like relu, sigmoid, softmax
## Lenet Network, mobilenet, vgg16, vgg19
## fully connected layer
## dense layer, flatten layer
## learning rate
## loss functions, categorical entropy etc
## different accuracy metrics
## what is the use of model.compile
## what is model.fitgenerator
## what is the use of batchsize
## what is a epoch
## What is steps per epoch
## What is model.evalute
## how to evaluate the final model
## diffrence between precision recall f1score support
## what are different verbose
## different types of saving the model as pickle, h5 and other
## test score and test accuracy in evaluation the model
## know about early stopping

***


### Preprocessing and reshaping
* Then we will process the images to optimise for the training the process
* Augment the images to make data more generic
* One hot encode the matrix
* Create the model and start the training process
* Once the process is done, we will plot the results, save the trained model and import it in test script to test it on using web cam


### Procedure
* We have our data of 10 digits in 10 different folders
* We need all the images in form list so that we can later send this list to our model

* First we will get the directories 
* Total directories and their names
* Store all the images in a list
* Before storing we need to resize the image as the original images might be too large
* We should also store the corresponding class ID of the images
* Convert images list to numpy array
* Splitting data as 80 - 20
* while splitting we shuffle the data because if we dont' that splitting will be as first 8 class in training and last 2 classes in testing

## Errors in Data Science

> Here all the below errors are called Loss Functions
> A loss function is the measure of how good a prediction model does in terms of being able to predict the expected outcome
> Most commonly used method of finding the minimum point of function is **GRADIENT DESCENT**
> Loss functions can be broadly categorized into 2 types: Classification and Regression Loss
> Loss function sometimes also called as the cost function

## Regression Errors

### Sum Of Errors (SE)

* This is the most basic loss function which is nothing but sum of errors in each iteration
* The error is the difference between predicted value and the actual value

### Sum Of Absolute Errors (SAE)

* This is just the sum of absolute values of errors
* Enhanced version of previous Sum of Errors concept
* There is one problem This loss function is not differentiable at 0 ( that is the derivate will not exist at 0)
* We need to differentiate the function and equate it to 0 to find the optimum point which is not possible here

### Sum Of Squared Errors (SSE)

* Here we are going to take the square instead of the absolute 
* It is very much differentiable at all points and gives non - negative errors
* Assume we are using this as our loss function, for a data set of 100 say our error is 200, if we increase data set to 500 our sum of squares will increase too, if the data set is 800, SSE will increase further, which is not fair at all as the error should decrease as we increase our sample data

### Mean Square Error or Mean Square Deviation (MSE)

* The above problem can be solved using the Mean Square Error
* It is defined as the average of square of the difference between actual and estimated values
* It is used to check how close estimates or forecast are to the actual values
* This is generally used for model evaluation measure for regression models, lower the value the better it is
* The Mean Square Error is used as default metric of evaluation of the performance of most regression algorithms
* The only issue with the MSE is that the order of loss is more than that of the data
* That assume we need to calculate error in meters if we calculate MSE then units change to meter square so we cannot directly correlate it with our data
* Another disadvantage of MSE is if our model makes single very bad prediction, the squaring part of the function magnifies the error
* But in many practical cases we don't care much about these outliers and are aiming for more of well rounded model that performs good enough on the majority

### Root Mean Squared Error (RMSE)

* Here we are not changing the loss function and the solution is still the same
* All we are doing is reducing the order of loss function by taking the root
* Here reducing the order means the units will be same that even if we do the square ( meter to meter square) we applying root ( meter square to meter) so that we can directly correlate the error to the data and compare

### Mean Absolute Error (MAE)

* To calculate MAE, we take the difference between our model prediction and ground truth, apply the absolute value to that difference, then average it out across the dataset
* Advantage of MAE is it directly covers the disadvantage of MSE, here the outliers doesnot get multiplied, and as we are taking the average errors are distribute linearly
* Disadvantage of this is if we are caring about the outliers, the MAE is not effective

### Huber Loss 

* It combines the best properties of both MSE and MAE
* In simple terms it can be defines that **for the loss value less than delta, use MSE, for loss values greater than deltause the MAE** 
* Delta should be defined carefully for this

## Classification Errors

> Here we use **Cross Entropy Loss**
> **Entropy** means the **impurity**


### Binary Cross Entropy - Logistic Regression

#### Need to finish this

### Multi Class Cross Entropy

#### Need to finish this

* Remember both MaxPooling and MaxPool are the same


### What is DBMS ? Mention advantages

* https://www.geeksforgeeks.org/advantages-of-database-management-system/

### Difference between excel and data base

* https://www.geeksforgeeks.org/difference-between-spreadsheet-and-database/

### What is a database

* A database is an organized collection of structured information, or data, typically stored electronically in a computer system. A database is usually controlled by a database management system (DBMS). Together, the data and the DBMS, along with the applications that are associated with them, are referred to as a database system, often shortened to just databas

### difference between data base and dbms

* A collection of related pieces of data, whose purpose is to solve the data management needs of an institution is called a Database.
* Database Management Systems (DBMS), on the other hand, are very complex software which save the data on the secondary storage devices and which are used to manipulate databases.

* https://www.geeksforgeeks.org/difference-between-database-and-dbms/

### What is RDBMS ? Properties..

* RDBMS stands for Relational Database Management Systems..

* All modern database management systems like SQL, MS SQL Server, IBM DB2, ORACLE, My-SQL and Microsoft Access are based on RDBMS

### Difference between DBMS and RDBMS

* https://www.javatpoint.com/difference-between-dbms-and-rdbms

##### Properties of relational databases

* Values are atomic. (An atomic value is a value that cannot be divided.)
* All of the values in a column have the same data type
* Each row is unique.
* The sequence of columns is insignificant ( The Sequence of Columns is Insignificant
This property states that the ordering of the columns in the relational table has no meaning. Columns can be retrieved in any order and in various sequences.)
* The sequence of rows is insignificant.
* Each column has a unique name.
* Integrity constraints maintain data consistency across multiple tables
* Integrity constraints are a set of rules. ... Integrity constraints ensure that the data insertion, updating, and other processes have to be performed in such a way that data integrity is not affected. Thus, integrity constraint is used to guard against accidental damage to the database.

### What is difference between SQL and NoSQL?

* SQL databases are relational, NoSQL databases are non-relational. ... SQL databases are table-based, while NoSQL databases are document, key-value, graph, or wide-column stores. SQL databases are better for multi-row transactions, while NoSQL is better for unstructured data like documents or JSON

### Types of database languages

* https://www.javatpoint.com/dbms-language
* https://www.geeksforgeeks.org/sql-ddl-dql-dml-dcl-tcl-commands/

### Difference between delete truncate and drop

* https://www.geeksforgeeks.org/difference-between-delete-drop-and-truncate/


### ACID properties

* https://www.geeksforgeeks.org/acid-properties-in-dbms/

### Difference between vertical and horizontal scaling in dbms

* While horizontal scaling refers to adding additional nodes, vertical scaling describes adding more power to your current machines. For instance, if your server requires more processing power, vertical scaling would mean upgrading the CPUs. You can also vertically scale the memory, storage, or network speed

* https://www.geeksforgeeks.org/horizontal-and-vertical-scaling-in-databases/

### What is sharding

* The word “Shard” means “a small part of a whole“. Hence Sharding means dividing a larger part into smaller parts.
* In DBMS, Sharding is a type of DataBase partitioning in which a large DataBase is divided or partitioned into smaller data, also known as shards. These shards are not only smaller, but also faster and hence easily manageable.

### Keys in DBMS

* https://www.javatpoint.com/dbms-keys
* https://www.geeksforgeeks.org/types-of-keys-in-relational-model-candidate-super-primary-alternate-and-foreign/
