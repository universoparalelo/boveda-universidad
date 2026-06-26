---
title: "What Is the Karpathy LLM Wiki Pattern? How to Build a Personal Knowledge Base With Claude"
source: "https://www.mindstudio.ai/blog/karpathy-llm-wiki-knowledge-base-pattern"
author:
  - "[[MindStudio Team]]"
published: 2026-04-10
created: 2026-06-26
description: "Andrej Karpathy's LLM Wiki uses plain text files instead of vector databases and is reportedly 70x more efficient than RAG. Here's how to build one."
tags:
  - "clippings"
---
## The Problem With How Most People Use AI for Research

Most people treat AI like a search engine — ask a question, get an answer, move on. The knowledge disappears. Next week, you ask the same question and get a slightly different answer. Nothing accumulates.

Andrej Karpathy, former Director of AI at Tesla and founding member of OpenAI, proposed something different: what if you kept a plain text knowledge base — a personal wiki — and fed it directly to an LLM like Claude? No vector databases. No RAG pipelines. No embeddings. Just text files and a long context window.

This is the **Karpathy LLM Wiki pattern**, and it’s reshaping how developers, researchers, and knowledge workers think about personal knowledge management with AI.

---

## What the Karpathy LLM Wiki Pattern Actually Is

The core idea is simple. You maintain a collection of plain text or Markdown files — your “wiki” — organized around topics, concepts, projects, or anything you care about. When you want to query that knowledge, you feed the files directly into an LLM like Claude and ask your question.

That’s it. No database. No indexing. No retrieval pipeline to maintain.

Karpathy’s framing draws on a basic observation: modern LLMs now have context windows large enough to hold an entire personal knowledge base. Claude 3.5 supports 200,000 tokens — roughly 150,000 words, or the equivalent of two novels. GPT-4 Turbo and Gemini 1.5 Pro have similar capacities.

REMY IS NOT

- ✕a coding agent
- ✕no-code
- ✕vibe coding
- ✕a faster Cursor

IT IS

✓a general contractor for software

The one that tells the coding agents what to build.

At that scale, you don’t *need* to retrieve the right chunk. You can just load everything in and let the model reason over it.

### The Difference Between a Wiki and a Note App

A personal wiki, in Karpathy’s usage, isn’t a Notion database or a Roam Research graph. It’s deliberately flat and portable:

- Plain `.txt` or `.md` files
- Human-readable without any app
- No proprietary format or lock-in
- Easy to version with Git
- Trivial to concatenate and pass to an LLM

The goal is durability and portability. Your knowledge base should work with any LLM that exists today or will exist in ten years.

---

## Why Plain Text Beats RAG for Personal Knowledge Bases

RAG (Retrieval-Augmented Generation) is the standard approach for giving LLMs access to external knowledge. You embed your documents as vectors, store them in a database, and retrieve relevant chunks at query time.

RAG is genuinely useful for large enterprise knowledge bases — tens of thousands of documents where you physically can’t fit everything in context. But for personal knowledge bases, it introduces significant overhead without clear benefit.

### The Case Against RAG at Personal Scale

Here’s what RAG requires that plain text doesn’t:

- An embedding model (or API calls to one)
- A vector database (Pinecone, Weaviate, Chroma, etc.)
- A chunking strategy that doesn’t cut off important context
- A retrieval step that might miss relevant information
- Ongoing maintenance as your knowledge base grows

Every one of these is a potential failure point. If your chunking strategy is wrong, the model gets partial context. If your retrieval is off, it misses the relevant note entirely. And you’re paying embedding costs on top of inference costs.

Plain text with a long context window sidesteps all of this. The model sees everything at once and can make connections across your entire knowledge base — something RAG fundamentally cannot do.

### The Efficiency Argument

The claim that the LLM Wiki pattern is significantly more efficient than RAG for personal use comes down to a few factors. With RAG, you’re making at least two API calls (embedding + generation), maintaining a separate database, and accepting the risk of retrieval failure. With direct context loading, you make one call and the model has complete information.

For a personal wiki of, say, 50,000–100,000 words — a realistic size for even a prolific note-taker — this fits comfortably within Claude’s context window. The total cost of a query is a single inference call.

That said, the efficiency equation flips at scale. If your knowledge base grows into millions of words, RAG becomes necessary. The Karpathy pattern is explicitly designed for *personal* knowledge — not enterprise document repositories.

---

## Why Claude Is Particularly Good for This Pattern

Not all LLMs are equally suited to this approach. Claude has a few specific properties that make it work well.

### Long Context Without Degradation

Claude 3.5 Sonnet and Claude 3 Opus both support 200K token contexts. But context length alone isn’t enough — some models degrade significantly in the middle of a long context (the “lost in the middle” problem, documented in [research from Stanford and others](https://arxiv.org/abs/2307.03172)).

## One coffee. One working app.

You bring the idea. Remy manages the project.

WHILE YOU WERE AWAY

✓Designed the data model

✓Picked an auth scheme — sessions + RBAC

✓Wired up Stripe checkout

✓Deployed to production

Live at yourapp.msagent.ai

Anthropic has specifically optimized Claude for long-context tasks. It performs well at retrieving and reasoning over information placed throughout a long document, not just at the start and end.

### Instruction-Following and Format Fidelity

Personal wikis often contain idiosyncratic formats — shorthand, personal taxonomies, half-finished notes. Claude handles ambiguous or loosely structured input reasonably well and tends to follow formatting instructions faithfully when returning answers.

### Low Hallucination Rate on Grounded Tasks

When Claude is given a clear document set and asked to answer from within it, it’s relatively reliable about staying grounded. For a personal knowledge base, you want the model to tell you what *you* wrote, not what it thinks you should have written.

---

## How to Build Your Own LLM Wiki With Claude

Here’s a practical implementation of the Karpathy LLM Wiki pattern. This works whether you’re a developer or not.

### Step 1: Set Up Your File Structure

Create a folder called something like `wiki/` or `brain/`. Inside it, create plain `.md` files organized by topic. Some approaches:

- One file per concept (`machine-learning.md`, `project-notes-q4.md`)
- One file per domain (`investing.md`, `health.md`, `work.md`)
- Chronological files (`2025-notes.md`) — less recommended for retrieval

Keep file names lowercase, hyphenated, and descriptive. Avoid nesting folders more than one level deep if you can.

### Step 2: Write for Future LLM Consumption

Your notes should be useful to both you and a future LLM. A few principles:

- Use headers to separate topics within a file
- Write in complete sentences where possible — the LLM does better with prose than telegraphic bullet points
- Add context when it might be ambiguous later (“This is about the React framework, not React from Emotion”)
- Date entries where recency matters

You don’t need to write perfectly. A messy note with real information beats an empty perfectly-formatted file.

### Step 3: Create a System Prompt

When querying your wiki, you’ll prepend a system prompt to your concatenated files. Here’s a basic structure:

```plaintext
You are a knowledge assistant for [your name]. Below is a personal wiki containing notes, research, and thinking on various topics. 

When answering questions:
- Answer only from the provided wiki content unless clearly asked to use general knowledge
- If the wiki doesn't contain relevant information, say so explicitly
- Quote relevant sections when helpful
- Note if information appears outdated or contradictory

---
[Your concatenated wiki content]
---
```

### Step 4: Concatenate and Query

To query your wiki, you need to combine all relevant files into one text blob. Simple approaches:

**Via command line:**

```bash
cat wiki/*.md > wiki_export.txt
```

**Via Python:**

```python
import os

wiki_dir = "./wiki"
combined = ""
for filename in os.listdir(wiki_dir):
    if filename.endswith(".md"):
        with open(os.path.join(wiki_dir, filename)) as f:
            combined += f"\n\n# {filename}\n\n" + f.read()
```

Then paste the combined text plus your system prompt into Claude’s API or interface.

### Step 5: Decide on Selective vs. Full Loading

For small wikis (under 100K words), load everything. For larger wikis, you have two options:

1. **Topic-based selection** — manually pick files relevant to your question
2. **Lightweight filtering** — use grep or fuzzy search to find potentially relevant files before loading
![Learn Hermes. Free. 1 hour.](https://i.mscdn.ai/1b7301c0-de42-4e46-b110-e9c55396e7ca/generated-images/fb67e638-9ac3-4c24-9136-cb4191563d07.png?fm=auto&w=1200)

Full loading is simpler and often better because it allows cross-topic connections you wouldn’t anticipate.

### Step 6: Automate the Query Interface (Optional)

If you’re doing this regularly, a simple script or workflow can make querying feel seamless. At minimum, automate the concatenation step so you’re not manually combining files before every session.

---

## Practical Use Cases

The LLM Wiki pattern is most valuable when you have knowledge that’s hard to find elsewhere — your own thinking, your project history, your personal research.

### Personal Research Database

If you read academic papers, newsletters, or books and take notes, your LLM wiki becomes a queryable research database. “What did I write about transformer attention mechanisms?” becomes a valid query instead of a search through disorganized files.

### Project Memory

Software teams or solo developers can maintain a wiki of architectural decisions, debugging notes, and lessons learned. Querying it with Claude surfaces relevant context before starting a new feature.

### Writing and Thinking Assistant

Feed your wiki to Claude and ask it to help you write something new. “Based on my notes on behavioral economics, help me outline an argument about pricing psychology” leverages your accumulated thinking rather than starting from scratch.

### Second Brain for Professionals

Knowledge workers — consultants, researchers, analysts — accumulate domain-specific knowledge over years. A personal wiki plus Claude turns that accumulated knowledge into an interactive resource.

---

## Automating Your LLM Wiki With MindStudio

Building the file structure and doing occasional manual queries is fine for personal use. But if you want to turn your LLM wiki into a proper workflow — something that runs automatically, integrates with your tools, and produces outputs beyond a chat window — [MindStudio](https://mindstudio.ai/) is worth looking at.

MindStudio is a no-code platform for building AI agents and workflows. It supports Claude natively alongside 200+ other models, and lets you build agents that do things like:

- Automatically ingest new notes you write in Google Docs or Notion into your wiki
- Run scheduled summaries of your knowledge base (“What did I learn this week?”)
- Answer questions about your wiki through a custom web app you can share with your team
- Trigger wiki updates when you add a bookmark, finish a meeting, or complete a task

The relevant piece here is MindStudio’s integration layer. It connects to 1,000+ tools — including Google Workspace, Notion, Airtable, and Slack — so your wiki doesn’t have to live in a folder you manually update. It can pull from wherever your notes actually live.

For example, you could build a MindStudio agent that watches a specific Notion database, extracts new notes each morning, formats them as Markdown, appends them to your wiki, and then runs a Claude query to synthesize what you’ve been learning. The whole thing runs on a schedule without you touching it.

If you want to explore this, [you can start building on MindStudio for free](https://mindstudio.ai/). The average agent takes 15 minutes to an hour to set up — no code required, and Claude is already built in.

---

## Frequently Asked Questions

### What is the Karpathy LLM Wiki pattern?

![Get set up on Hermes in 1 hour](https://i.mscdn.ai/1b7301c0-de42-4e46-b110-e9c55396e7ca/generated-images/528080de-ba99-48dc-966c-343c06c614a9.png?fm=auto&w=1200)

It’s an approach to personal knowledge management where you store notes in plain text or Markdown files and query them by feeding the files directly into a long-context LLM like Claude. Proposed by Andrej Karpathy, the idea is to avoid complex retrieval infrastructure by relying on the LLM’s large context window to reason over your entire knowledge base at once.

### How is this different from RAG (Retrieval-Augmented Generation)?

RAG splits your documents into chunks, embeds them as vectors, and retrieves relevant chunks at query time. The LLM Wiki pattern skips all of that — it loads the full knowledge base directly into the model’s context window. RAG is better for large enterprise document stores. Direct context loading is simpler and often more accurate for personal knowledge bases that fit within a model’s context limit.

### How much text can Claude actually handle?

Claude 3.5 Sonnet and Claude 3 Opus support 200,000 token contexts, which is roughly 150,000 words. That’s enough for a substantial personal knowledge base — most people’s notes over years of use fall well within this range. Claude is also specifically optimized to perform well across long contexts, not just at the beginning and end of a document.

### Do I need to know how to code to implement this?

No. The simplest version requires nothing more than creating text files and pasting their contents into Claude’s interface (Claude.ai supports very long inputs). For automation and integrations, tools like MindStudio let you build full workflows without writing code. Developers who want more control can use a simple Python script for concatenation and the Claude API for querying.

### What’s the best file format for an LLM wiki?

Plain Markdown (`.md`) is the best choice. It’s human-readable, LLMs understand its structure natively, it renders nicely in most editors, and it’s trivial to version with Git. Avoid formats that require proprietary apps to read — the whole point is portability and longevity.

### Can this work with other LLMs besides Claude?

Yes. Gemini 1.5 Pro (1 million token context) and GPT-4 Turbo (128K context) can both work with this pattern. Claude is often recommended because of its strong long-context performance and low hallucination rate on grounded tasks, but the pattern itself is model-agnostic. As context windows continue to grow across the industry, the LLM Wiki approach will only become more viable.

---

## Key Takeaways

- The Karpathy LLM Wiki pattern stores knowledge as plain text files and feeds them directly into a long-context LLM at query time — no vector databases, no retrieval pipelines
- Claude’s 200K token context window can hold an entire personal knowledge base, making full-context loading practical for most users
- For personal-scale knowledge (up to ~150,000 words), this approach is simpler, cheaper, and often more accurate than RAG
- The basic implementation requires nothing more than text files and a concatenation step — it takes minutes to set up
- For automated ingestion, scheduled queries, and tool integrations, platforms like [MindStudio](https://mindstudio.ai/) let you build complete wiki workflows without code

If you’ve been looking for a way to actually use your notes — not just collect them — this pattern is worth trying. Start small: one folder, a handful of files, and a Claude query. See what it surfaces from your own thinking.