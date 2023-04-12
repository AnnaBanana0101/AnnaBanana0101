import openai

from difflib import SequenceMatcher

openai.api_key= "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"

messages = [{"role": "system", "content": "You are a Machine Learning tutor, check if the user defines topics correctly"}]

#THE LIST OF TOPICS
topics = [
    {"topic": "Machine Learning", "intro": "Let's learn about Machine Learning", "questions": ["What is Machine Learning?"]},
    {"topic": "Steps in Training", "intro": "Now, let's move on to Steps in Training.", "questions": ["What are the key components of Steps in Training?"]},
    {"topic": "Data Collection", "intro": "Now, let's move on to Data Collection.", "questions": ["What is the most important thing to remember when working with Data Collection?"]},
    {"topic": "Data Preprocessing", "intro": "Two down! Let's now learn about Data Preprocessing.", "questions": ["What do you mean by Data Preprocessing?"]},
    {"topic": "Training", "intro": "Going deeper, let's learn about Training.", "questions": ["What is Training in Machine Learning?"]},
    {"topic": "Evaluation", "intro": "Finally, let's look into Evaluation of data models", "questions": ["What does Data Evaluation in Machine Learning mean??"]}
]

#THE ITERATOR TO KEEP TRACK OF THE TOPIC NUMBER
topic_index=0

#THE PROMPTS FOR CHATGPT FOR EACH TOPIC
topic_ml= "What is Machine Learning?"
topic_steps= "What are the steps in training in Machine Learning? Give the answer in one line"
topic_data= "What is Data Collection in Machine Learning and how does it work?"
topic_prep= "What is data preprocessing?"
topic_training= "What is training a model in machine learning?"
topic_eval= "What is model evaluation in Machine Learning?"

#THE LIST OF PROMPTS FOR EACH TOPIC
topic_prompts=[
    topic_ml,
    topic_steps,
    topic_data,
    topic_prep,
    topic_training,
    topic_eval
]

#WELCOME MESSAGE FOR THE STUDENTS
print("Tutor: Welcome to your Machine Learning tutor!\nThis course will help you understand Machine Learning and the different steps involved in it one by one.\nIf you don't understand something, you can always ask me to repeat by saying \"No\" when asked. Let's get started!")

#TILL ALL THE TOPICS ARE OVER
while topic_index<len(topics):

    current_topic= topics[topic_index]["topic"]       
    current_intro= topics[topic_index]["intro"]
    current_questions= topics[topic_index]["questions"]
    current_prompt= topic_prompts[topic_index]
    
    #------------------------------------------------------------TEACH THE CURRENT TOPIC--------------------------------------------------------------------------------
    print("\n\n")
    print("Tutor: "+current_intro)
    interactive_question = "What do you know about " + current_topic + "?"
    answer1 = input("Tutor: " + interactive_question + "\nYou: ")
    response = openai.Completion.create(
        engine="text-davinci-002",
        prompt= f"Question: {current_prompt}\nAnswer:",
        max_tokens=2000,
        n=2,
        stop=None,
        temperature=0.7
    )
    chatbot_response = response.choices[0].text.strip()

    topic_info= chatbot_response                                       #STORING THE SUBJECT MATTER FOR COMPARISION WITH THE STUDENT'S ANSWER LATER

    messages.append({"role": "assistant", "content": chatbot_response})
    print("\nTutor: "+ chatbot_response)

    print("Got it?")
    answer2= input("You: ").lower()

    while "no" in answer2:                                              #IF THE STUDENT REPLIES "NO" TO THE PROMPT OF HAVING UNDERSTOOD THE CURRENT TOPIC
            
            response = openai.Completion.create(
            engine="text-davinci-002",
            prompt= f"Question: {current_prompt}\nAnswer:",
            max_tokens=2000,
            n=2,
            stop=None,
            temperature=0.7
        )
            
            chatbot_response = response.choices[0].text.strip()
            print("\nTutor: No problem! I'll explain again. " + chatbot_response)

            print("Tutor: Got it?")

            answer2= input("You: ").lower()

            if "no" not in answer2:
                break

    print("\n")

    #-------------------------------------------------------CHECK THE STUDENT'S KNOWLEDGE--------------------------------------------------------------------------

    print("Tutor: Now that you learned what "+current_topic+" is, let's test your knowledge!")

    print("Tutor: "+ current_questions[0])

    answer= input("You: ")
    

    response = openai.Completion.create(
            engine="text-davinci-002",
            prompt= f"Question:{current_prompt}\nIs this correct? {answer}\nAnswer:",
            max_tokens=60,
            n=1,
            stop=None,
            temperature=0.7
        )
    
    
    chatbot_response = response.choices[0].text.strip()
    
    chatbot_response= chatbot_response.lower()
    #print("Tutor: "+ chatbot_response)
    list= chatbot_response.split()
    

    if 'yes,' in list or 'correct' in list:                                         #CHECKING THE STUDENT ANSWER BASED ON THE CHATGPT RESPONSE TO PROMPT "IS THIS CORRECT" AND SIMILARITY
        
        print("Tutor: Good job!")
        topic_index+=1
                
    else:
        similarity_threshold = 0.2

        similarity_score = SequenceMatcher(None, answer.lower(), topic_info.lower()).ratio()
        similarity_score2= SequenceMatcher(None, answer.lower(), chatbot_response.lower()).ratio()

        if similarity_score >= similarity_threshold or similarity_score2>=similarity_threshold:
            print("Tutor: Great!")
            topic_index+=1
        else:
            print("Tutor: Oops, not quite! Let's go over the topic again!")         #IF INCORRECT ANSWER, TEACH THE TOPIC AGAIN
            continue 


    messages.append({"role": "assistant", "content": chatbot_response})
    
print("\n\nCongratutaltions! You have successfully finished the course!")








    



