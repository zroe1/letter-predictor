# Letter Predictor
Using a linear regression model and publicly available data, my code predicts the final letter in five-letter words. The accuracy is ~20% which is significantly greater than a random algorithm (~3.8%).

## How it works

There are two files that do significant work to create the model in this repository:

<ol>
  <li><b>words_to_tensorflow_readable.c:</b> a file written in C that takes the csv file in the oldCSVfiles folder containing common words and their part of speech (<b>wordFrequency.csv</b>) and creates a new csv in a format that is easily used by tensorflow (ASCII numbers instead of letters and a different column for each letter). By modifying the global variables for the start line and end line in the top of the C file, I was able to create <b>training.csv</b> and <b>eval.csv</b> (one file to train the model and the other to evaluate it). For the output that would contain all the lines of the file, I have included <b>output.csv</b> in the oldCSVfiles folder.</li>
  <li><b>letterpredictor.ipynb:</b> the notebook that contains the code that trains and evaluates the linear-regression model. Linear-regression is a common machine learning algorithm that can predict outcomes based on a labeled dataset like the one in this example.</li>
</ol>

## Performance

Overall, the model was able to perform at about 20% accuracy (more consistently at a bit lower though at ~18%) which is pretty strong considering that a randomly-choosing model would perform at only about ~3.8%. This accuracy demonstrates strong and impressive performance considering the size of the dataset and the challenge of the problem.

<img width="730" alt="Screenshot 2023-06-13 at 5 58 59 PM" src="https://github.com/zroe1/letterPredictor/assets/114773939/00ed51e2-bb3d-40f6-abaf-2bb8dbc23b7a">

Take the word "flame" for example. In this case, the model was able to correctly predict that the final letter in the string "flam" was the character "e" (ASCII character 101), giving this character a roughly 45% chance of being correct as shown below:

<img width="730" alt="Screenshot 2023-06-13 at 6 00 52 PM" src="https://github.com/zroe1/letterPredictor/assets/114773939/828574ca-1dc1-41b5-844d-2369fd5aaf02">

The model also seems to be good at having a bias against characters that are extremely unlikely to end a five letter word. For the string "flam", the model gives a close to zero probability that the final character in the string is an "x" (ASCII character 120).

<img width="730" alt="Screenshot 2023-06-13 at 6 00 04 PM" src="https://github.com/zroe1/letterPredictor/assets/114773939/0b4c648f-a509-42fe-8b14-9a50c540e6e2">

To be fair, it's performance is far from perfect. For the same string "flam", the model gave a 31% likelihood that the final character was a "t" (ASCII character 116) which doesn't seem correct at all from a human perspective.

<img width="730" alt="Screenshot 2023-06-13 at 6 01 08 PM" src="https://github.com/zroe1/letterPredictor/assets/114773939/fc740fb7-8bc7-44ec-b27a-6f6a8f1ea5c1">

## Sources
<ul>
  <li>List of words and part of speech data used to train the model was barrowed from www.wordfrequency.info</li>
  <li>The linear regression section of the course https://www.youtube.com/watch?v=tPYj3fFJGjk was heavily referenced to build this model. The course, at the time it was made, was mostly just an in-depth walkthrought of the tensorflow documentation.</li>
</ul>
