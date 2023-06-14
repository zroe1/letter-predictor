# Letter Predictor
Using a linear regression model and publicly available data, my code predicts the final letter in five-letter words.

## Preformance

Overall, the model was able to preform at about 20% accuracy (more consistently a bit lower though at ~18%) which is pretty strong considering that a randomly-choosing model would preform at only about ~3.8%. This accuracy demonstrates strong and impressive preformance considering the size of the dataset and the challenge of the problem.

<img width="730" alt="Screenshot 2023-06-13 at 5 58 59 PM" src="https://github.com/zroe1/letterPredictor/assets/114773939/00ed51e2-bb3d-40f6-abaf-2bb8dbc23b7a">

Take the word "flame" for example. In this case, the model was able to correctly predict that the final letter in the string "flam" was the character "e" (ASCII character 101), giving this character a roughly 45% chance of being correct as shown below:

<img width="730" alt="Screenshot 2023-06-13 at 6 00 52 PM" src="https://github.com/zroe1/letterPredictor/assets/114773939/828574ca-1dc1-41b5-844d-2369fd5aaf02">

The model also seems to be good at having a bias against characters that are extremely unlikely to end a five letter word. For the string "flam", the model gives a close to zero probability that the final character in the string is an "x" (ASCII character 120).

<img width="730" alt="Screenshot 2023-06-13 at 6 00 04 PM" src="https://github.com/zroe1/letterPredictor/assets/114773939/0b4c648f-a509-42fe-8b14-9a50c540e6e2">

To be fair, it's preformance is far from perfect. For the same string "flam", the model gave a 31% likelyhood that the final character was a "t" (ASCII character 116) which doesn't seem correct at all from a human perspective.

<img width="730" alt="Screenshot 2023-06-13 at 6 01 08 PM" src="https://github.com/zroe1/letterPredictor/assets/114773939/fc740fb7-8bc7-44ec-b27a-6f6a8f1ea5c1">

## Sources
<ul>
  <li>List of words and part of speech data used to train the model was barrowed from www.wordfrequency.info</li>
  <li>The linear regression section of the course https://www.youtube.com/watch?v=tPYj3fFJGjk was heavily referenced to build this model. The course, at the time it was made, was mostly just an in-depth walkthrought of the tensorflow documentation.</li>
</ul>
